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

    bool isPhase1;
    std::string phaseMapPath;
    int gameState;

    int Phase1(sf::RenderWindow &window);
    int Phase2(sf::RenderWindow &window);

    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);

    int escPressed(sf::RenderWindow &window);

    void clearEverything();
    void restartEverything();

public:
    PhaseManager();
    ~PhaseManager();

    int Start(sf::RenderWindow &window);

    void setIsPhaseOne(bool phase);
};