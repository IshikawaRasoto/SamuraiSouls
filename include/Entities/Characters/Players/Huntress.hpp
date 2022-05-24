#pragma once

#include "Entities/Character/Character.hpp"
#include "Managers/Input.hpp"
using namespace Managers;

class Huntress{
    private:
        int points;

    public:
        Huntress(const bool isPlayerOne = 1, InputManager* pIM = nullptr);
        ~Huntress();

        const bool isPlayerOne() const;
        void updatePts(int points);
        const bool getPts() const;
        
};
