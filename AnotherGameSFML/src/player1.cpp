#include "../header/player1.h"

Player1::Player1(sf::Vector2f pos, int hp)
{
    this->position = pos;
    this->walkSpeed = 4;

    this->hp = hp;
    hpBar.setFillColor(sf::Color::Green);
    rect.setSize(sf::Vector2f(32, 32));

    sprite.setTexture(*(Data::getInstance()->getPlayer1Texture()));
    sprite.setPosition(position);
    // Arrumado o quadrado do personagem para 32x32         para 48x48 (1.021, 1)
    sprite.setScale(sf::Vector2f(0.6666667, 0.6666667));
    controler = 1;
    cont = 0;
    right = false;

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
        cont++;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (position.x <= ((130 * 32) - 40)))
    {
        speed.x = walkSpeed;
        position.x += speed.x;
        right = true;
        cont++;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        jump();
    gravity();
    AnimationSprite();

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

void Player1::AnimationSprite()
{
    // Se quiser ver a animacao do personagem sem precisar deixar o botao apertado, tira o comentario
    //cont++;
    if (!(cont % 25))
        controler++;
    if (controler > 2)
        controler = 0;
    if (cont > 10000)
        cont = 0;
    if (right)
        sprite.setTextureRect(sf::IntRect(47 * controler, 48, 47, 48));
    else
        sprite.setTextureRect(sf::IntRect(47 * controler, 0, 47, 48));
}