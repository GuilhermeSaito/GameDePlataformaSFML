#pragma once

#include "entity.h"

class Player1 : public Entity
{
private:
    int pointsAcquired;
    bool right;

    void AdjustSprite();

public:
    Player1(sf::Vector2f pos = {200, 500}, int hp = 100);
    ~Player1();

    void Movimentation();
    void DrawPlayer1(sf::RenderWindow &window);
};