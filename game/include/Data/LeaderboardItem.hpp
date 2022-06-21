#pragma once

#include <string>

namespace Data{

struct LeaderboardItem{
    std::string name;
    int points;

    LeaderboardItem(std::string name, int points);

    bool operator>(LeaderboardItem &item);
    bool operator<(LeaderboardItem &item);
    bool operator==(LeaderboardItem &item);
};

}