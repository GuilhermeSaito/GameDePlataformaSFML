#include "../header/entity.h"

Entity::Entity()
{
    speed = sf::Vector2f(0, 0);
    gravityAcceleration = 1.1;
    jumpSpeed = -20;
    onGround = false;
}

Entity::~Entity()
{
}

sf::FloatRect Entity::getBoundBox()
{
    return sf::FloatRect(position.x, position.y, rect.getSize().x, rect.getSize().y);
}

sf::Vector2f Entity::getPosition()
{
    return position;
}

sf::Vector2f Entity::getSize()
{
    return rect.getSize();
}

void Entity::jump()
{
    if (onGround)
    {
        speed.y += jumpSpeed;
        onGround = false;
    }
}

void Entity::gravity()
{
    if (!onGround)
    {
        speed.y += gravityAcceleration;
        position.y += speed.y;
    }
}

// speed.x > 0 = Andando para a direita     speed.x < 0 = Andando para a esquerda
void Entity::collideX(Tile *tile)
{
    if (speed.x > 0)
        position.x = tile->getBoundBox().left - rect.getSize().x;
    else if (speed.x < 0)
        position.x = tile->getBoundBox().left + rect.getSize().x;
    speed.x = 0;
}

// Como no SFML, para baixo eh Positivo e para cima eh Negativo
// speed.y > 0 = Caindo             speed.y < 0 = Pulando
void Entity::collideY(Tile *tile)
{
    if (speed.y > 0)
    {
        onGround = true;
        position.y = tile->getBoundBox().top - rect.getSize().y;
    }
    else if (speed.y < 0)
    {
        onGround = false;
        position.y = tile->getBoundBox().height + rect.getSize().y;
    }
    speed.y = 0;
}