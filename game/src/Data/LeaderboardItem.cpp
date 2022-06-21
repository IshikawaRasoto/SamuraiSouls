#include "Data/LeaderboardItem.hpp"

using namespace Data;

LeaderboardItem::LeaderboardItem(std::string name, int points){
    this->name = name;
    this->points = points;
}

bool LeaderboardItem::operator<(LeaderboardItem &item){
    return points < item.points;
}

bool LeaderboardItem::operator>(LeaderboardItem &item){
    return points > item.points;
}

bool LeaderboardItem::operator==(LeaderboardItem &item){
    return points == item.points;
}