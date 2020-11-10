#pragma once

#include "data.h"
#include "tile.h"

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
    float jumpSpeed;
    float gravityAcceleration;
    bool onGround;

    sf::Sprite sprite;

public:
    Entity();
    ~Entity();

    sf::FloatRect getBoundBox();

    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f pos);
    sf::Vector2f getSize();
    sf::Vector2f getSpeed();

    int getHp();
    void setHp(int h);

    void jump();
    void gravity();
    void setOnGround(bool oG);

    void collideX(Tile *tile);
    void collideY(Tile *tile);
};