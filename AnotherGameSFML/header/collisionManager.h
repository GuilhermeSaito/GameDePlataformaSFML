#pragma once

// Vai verificar se as colisoes vao ocorrer, caso ocorre, sera tratado na classe Entity
#include "player1.h"
#include "phaseMap.h"

class CollisionManager
{
private:
    Player1 *player1;
    PhaseMap *phaseMap;

public:
    CollisionManager();
    ~CollisionManager();
    void setElements(Player1 *p1, PhaseMap *pM);
    void StartVerifyCollision();
    void VeirfyCollisionPlayer1();
};