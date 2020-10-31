#pragma once

// Manage the 2 phases of the game

// Player1 stantiated here
#include "player1.h"
#include "phaseMap.h"

class PhaseManager
{
private:
    Player1 player1;
    PhaseMap phaseMap;

public:
    PhaseManager();
    ~PhaseManager();

    int Start(sf::RenderWindow &window);
};