#include "Data/Leaderboard.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

#include "Sort/Sort.hpp"

using namespace Data;

bool Leaderboard::fileExists(){
    std::ifstream file(LEADERBOARD_FILENAME);

    return file.good();
}

bool Leaderboard::saveName(std::string name, int points){
    bool fileAlreadyExists = fileExists();

    /*
        O modo std::ios_base::app faz com que o programa mude para o final do arquivo toda vez que 
        um novo texto é escrito.
    */

    std::ofstream file(LEADERBOARD_FILENAME, std::ios_base::app);

    if(!file.is_open()){
        std::cout << "[Leaderboard] Erro ao abrir \"" << LEADERBOARD_FILENAME << "\".\n";
        return false;
    }

    if(fileAlreadyExists){
        file << "\n";
    }

    file << name << "," << points;

    file.close();

    return true;
}

std::vector<LeaderboardItem*> Leaderboard::getItems(){
    std::ifstream file(LEADERBOARD_FILENAME);
    std::vector<LeaderboardItem*> items;

    if(!file.is_open()){
        std::cout << "[Leaderboard] Erro ao abrir \"" << LEADERBOARD_FILENAME << "\", enquanto tentava obter itens.\n";
        return items;
    }

    std::string line, name, aux;
    int points;

    while(std::getline(file, line)){
        std::istringstream is(line);

        std::getline(is, name, ',');
        std::getline(is, aux, '\n');

        if(!name.size() || !aux.size()){
            std::cout << "[Leaderboard] Erro ao ler \"" << LEADERBOARD_FILENAME << "\". Formato inválido.\n";
            
            for(auto item : items){
                if(item) 
                    delete item;
            }

            items.clear();

            return items;
        }

        points = std::stoi(aux);

        items.push_back(new LeaderboardItem(name, points));
    }

    file.close();

    return items;
}

void Leaderboard::sort(std::vector<LeaderboardItem*> &items){
    Sort<LeaderboardItem*>::quickSortWithPointers(items);
}