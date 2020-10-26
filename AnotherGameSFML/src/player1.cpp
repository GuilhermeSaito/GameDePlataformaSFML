#include "../header/player1.h"

Player1::Player1(sf::Vector2f pos, int hp)
{
    this->position = pos;
    this->walkSpeed = 10.f;

    this->hp = hp;
    hpBar.setFillColor(sf::Color::Green);
    rect.setSize(sf::Vector2f(32, 32));

    sprite.setTexture(*(Data::getInstance()->getPlayerRightImage()));
    sprite.setPosition(position);
    right = true;

    pointsAcquired = 0;
}

Player1::~Player1()
{
}

void Player1::Movimentation()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (position.x >= 40))
    {
        speed.x = -walkSpeed;
        position.x += speed.x;
        right = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (position.x <= ((175 * 32) - 40)))
    {
        speed.x = walkSpeed;
        position.x += speed.x;
        right = true;
    }
    AdjustSprite();

    rect.setPosition(position);
    sprite.setPosition(rect.getPosition());

    // Isso daqui vai fazer sentido mais tarde, quando focar a camera no player1
    hpBar.setSize(sf::Vector2f(hp + (32 * 6), 20));
}

void Player1::DrawPlayer1(sf::RenderWindow &window)
{
    hpBar.setPosition(rect.getPosition().x - 32 * 17, window.getSize().y - (window.getSize().y - 32 * 2));

    window.draw(sprite);
    window.draw(hpBar);
}

void Player1::AdjustSprite()
{
    if (right)
        sprite.setTexture(*(Data::getInstance()->getPlayerRightImage()));
    else
        sprite.setTexture(*(Data::getInstance()->getPlayerLeftImage()));
}