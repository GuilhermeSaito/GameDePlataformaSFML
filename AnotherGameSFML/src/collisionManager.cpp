#include "../header/collisionManager.h"

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::setPlayerElement(Player1 *p1)
{
    player1 = p1;
}

void CollisionManager::setPhaseMapElement(PhaseMap *pM)
{
    phaseMap = pM;
}

void CollisionManager::VerifyCollision()
{
    VeirfyCollisionPlayer1();
}

void CollisionManager::VeirfyCollisionPlayer1()
{
    int i, j;
    float tilePosition;

    // Player x Tile (y axix)
    for (j = player1->getPosition().y / 32; i < ((player1->getPosition().y + player1->getSize().y) / 32); i++)
    {
        std::cout << "Place Y: " << player1->getPosition().y << "\n";
        if (phaseMap->isValidTile(player1->getPosition().x / 32, j))
            continue;
        Tile *tile = phaseMap->getTile(player1->getPosition().x / 32, j);
        if (player1->getBoundBox().intersects(tile->getBoundBox()))
        {
            std::cout << "Colide Y\n";
            tilePosition = tile->getPosition().y;
            player1->collideY(tile);
        }
    }

    // Acho que essa colisao com o eixo x pode dar errado por causa desse primeiro if, soh acho...

    // Player x Tile (x axis)   prevenindo que ocorra colisao em x quando o player afundar no tile
    if (player1->getPosition().y <= tilePosition)
        for (i = player1->getPosition().x / 32; i < ((player1->getPosition().x + player1->getSize().x) / 32); i++)
        {
            if (phaseMap->isValidTile(i, player1->getPosition().y / 32))
                continue;
            Tile *tile = phaseMap->getTile(i, player1->getPosition().y / 32);
            if (player1->getBoundBox().intersects(tile->getBoundBox()))
            {
                std::cout << "Colide X\n";
                player1->collideX(tile);
            }
        }
}