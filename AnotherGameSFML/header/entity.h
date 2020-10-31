#pragma once

#include "data.h"

// Classe base para
// Player1 e Player2,   Enemy...

class Entity
{
protected:
    int hp;
    sf::RectangleShape hpBar;

    // Para a colisao
    sf::RectangleShape rect;

    sf::Vector2f position;
    sf::Vector2f speed;
    float walkSpeed;

    sf::Sprite sprite;

public:
    sf::FloatRect getBoundBox();
    sf::Vector2f getPosition();
};