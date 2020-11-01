#pragma once

// Manage the 2 phases of the game

// Player1 stantiated here,     The tiles too
#include "player1.h"
#include "phaseMap.h"
#include "collisionManager.h"

class PhaseManager
{
private:
    Player1 player1;
    PhaseMap phaseMap;
    CollisionManager collisionManager;

public:
    PhaseManager();
    ~PhaseManager();

    int Start(sf::RenderWindow &window);
};