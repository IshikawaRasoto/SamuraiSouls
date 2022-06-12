#pragma once

#include <string>
#include <vector>

#include "./LeaderboardItem.hpp"

#define LEADERBOARD_FILENAME "leaderboard.txt"

namespace Data{

class Leaderboard{
public:
    static bool fileExists();
    static bool saveName(std::string name, int points);
    static std::vector<LeaderboardItem*> getItems();
    static void sort(std::vector<LeaderboardItem*> &items);
};

}