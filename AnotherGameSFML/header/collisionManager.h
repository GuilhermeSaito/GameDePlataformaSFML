#pragma once

// Vai verificar se as colisoes vao ocorrer, caso ocorre, sera tratado na classe Entity
#include "player1.h"
#include "phaseMap.h"

class CollisionManager
{
private:
    Player1 *player1;
    PhaseMap *phaseMap;

    void VeirfyCollisionPlayer1();

public:
    CollisionManager();
    ~CollisionManager();
    void setPlayerElement(Player1 *p1);
    void setPhaseMapElement(PhaseMap *pM);
    void VerifyCollision();
};