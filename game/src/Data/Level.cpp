#include "Data/Level.hpp"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace Data;

void Level::saveSnapshots(std::vector<Snapshots::EntitySnapshot*> snapshots, Snapshots::LevelSnapshot* levelSnapshot){
    std::string filename = LEVELDATA_SNAPSHOT_BASE_FILENAME + std::to_string(levelSnapshot->getStateId()) + LEVELDATA_SNAPSHOT_FILE_EXTENSION;

    std::ofstream file(filename);

    if(!file.is_open()){
        std::cout << "[LevelData] Erro ao abrir \"" << filename << "\", enquanto tentava salvar snapshots.";
        return;
    }

    file << levelSnapshot->toString() << "\n";

    for(int i = 0; i < snapshots.size(); i++){
        file << snapshots[i]->toString();

        if(i < snapshots.size()-1){
            file << "\n";
        }
    }

    file.close();
}

Characters::Player* Level::buildPlayer(Snapshots::PlayerSnapshot* playerSnapshot){
    Characters::Player *player = new Characters::Player(
        playerSnapshot->getPosition(),
        playerSnapshot->getIsPlayerOne()
    );

    player->setFacingLeft(playerSnapshot->getFacingLeft());
    player->setSpeed(playerSnapshot->getSpeed());
    player->setHp(playerSnapshot->getHp());

    return player;
}

Characters::Enemies::Boss* Level::buildBoss(Snapshots::EntitySnapshot* entitySnapshot, Entities::FireBall *fireball){
    Characters::Enemies::Boss* boss = new Characters::Enemies::Boss(
        entitySnapshot->getPosition(),
        fireball
    );

    boss->setSpeed(entitySnapshot->getSpeed());
    boss->setFacingLeft(entitySnapshot->getFacingLeft());

    return boss;
}

Lists::EntityList* Level::loadSnapshots(Patterns::StateId levelState){
    std::ifstream file(LEVELDATA_SNAPSHOT_BASE_FILENAME + std::to_string(levelState) + LEVELDATA_SNAPSHOT_FILE_EXTENSION);

    if(!file.is_open()){
        std::cout << "[LevelData] Não existe um save para o level \"" << levelState << "\"\n";
        return nullptr;
    }

    std::string line, aux;
    Lists::EntityList *list = new Lists::EntityList();

    std::getline(file, line);
    if(!line.length()){
        std::cout << "[LevelData] Erro ao carregar snapshots com o arquivo \"" << levelState << "\". Formato inválido\n";
        return nullptr;
    }

    int points = std::stoi(line);

    Characters::Player *player1 = nullptr, *player2 = nullptr;
    Snapshots::PlayerSnapshot *playerSnapshot;
    Snapshots::EntitySnapshot *entitySnapshot;

    while(std::getline(file, line)){
        sf::Vector2f position;
        sf::Vector2f speed;
        bool isPlayerOne, facingLeft;
        int hp;
        Type entityType;
        playerSnapshot = nullptr;
        entitySnapshot = nullptr;

        std::istringstream is(line);

        std::getline(is, aux, ',');

        entityType = static_cast<Type>(std::stoi(aux));

        std::getline(is, aux, ',');
        position.x = std::stof(aux);

        std::getline(is, aux, ',');
        position.y = std::stof(aux);

        std::getline(is, aux, ',');
        speed.x = std::stof(aux);

        std::getline(is, aux, ',');
        speed.y = std::stof(aux);

        if(entityType == Type::Player){

            std::getline(is, aux, ',');
            facingLeft = std::stoi(aux);

            std::getline(is, aux, ',');
            hp = std::stoi(aux);

            std::getline(is, aux, '\n');
            isPlayerOne = stoi(aux);

            playerSnapshot = new Snapshots::PlayerSnapshot(
                isPlayerOne,
                hp,
                position,
                speed,
                facingLeft
            );
        }else{
            std::getline(is, aux, '\n');
            facingLeft = std::stoi(aux);

            entitySnapshot = new Snapshots::EntitySnapshot(
                entityType,
                position,
                speed,
                facingLeft
            );
        }

        switch(entityType){
            case Type::Player:{
                Characters::Player *player = buildPlayer(playerSnapshot);
                if(player->getIsPlayerOne()){
                    player1 = player;
                }else{
                    player2 = player;
                }
                list->addEntity(player);
                break;
            }
            case Type::Boss:{
                Entities::FireBall *fireball = new Entities::FireBall(entitySnapshot->getPosition());
                list->addEntity(fireball);
                list->addEntity(buildBoss(entitySnapshot,fireball));
                break;
            }
            case Type::Goblin:
                list->addEntity(buildEnemy<Characters::Enemies::Goblin>(entitySnapshot));
                break;
            case Type::Skeleton:
                list->addEntity(buildEnemy<Characters::Enemies::Skeleton>(entitySnapshot));
                break;
            case Type::Barrel:
                list->addEntity(buildEntity<Objects::Obstacles::Barrel>(entitySnapshot));
                break;
            case Type::Gravestone:
                list->addEntity(buildEntity<Objects::Obstacles::Gravestone>(entitySnapshot));
                break;
            case Type::Thorns:
                list->addEntity(buildEntity<Objects::Obstacles::Thorns>(entitySnapshot));
                break;
            case Type::Box:
                list->addEntity(buildEntity<Objects::Obstacles::Box>(entitySnapshot));
                break;
            case Type::Wagon:
                list->addEntity(buildEntity<Objects::Obstacles::Wagon>(entitySnapshot));
                break;   
        }

    }

    player1->setPts(points);

    for(int i = 0; i < list->getSize(); i++){
        Type entityType = (*list)[i]->getType();

        if(entityType == Type::Goblin || entityType == Type::Boss || entityType == Type::Skeleton){
            (static_cast<Enemies::Enemy*>((*list)[i]))->setPlayer1(player1);
            (static_cast<Enemies::Enemy*>((*list)[i]))->setPlayer2(player2);
        }
    }

    file.close();

    return list;
}