#include "../header/collisionManager.h"

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::setElements(Player1 *p1, PhaseMap *pM)
{
    player1 = p1;
    phaseMap = pM;
}

void CollisionManager::StartVerifyCollision()
{
    VeirfyCollisionPlayer1();
}

void CollisionManager::VeirfyCollisionPlayer1()
{
    int i, j;
    // Player x Tile (x axis)
    for (i = player1->getPosition().x / 32; i < ((player1->getPosition().x + player1->getSize().x) / 32); i++)
    {
        if (phaseMap->isValidTile(i, player1->getPosition().y / 32))
            continue;
        Tile *tile = phaseMap->getTile(i, player1->getPosition().y / 32);
        if (player1->getBoundBox().intersects(tile->getBoundBox()))
            player1->collideX(tile);
    }

    // Player x Tile (y axix)
    for (j = player1->getPosition().y / 32; i < ((player1->getPosition().y + player1->getSize().y) / 32); i++)
    {
        if (phaseMap->isValidTile(player1->getPosition().x / 32, j))
            continue;
        Tile *tile = phaseMap->getTile(player1->getPosition().x / 32, j);
        if (player1->getBoundBox().intersects(tile->getBoundBox()))
            player1->collideY(tile);
    }
}