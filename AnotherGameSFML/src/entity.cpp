#include "../header/entity.h"

sf::FloatRect Entity::getBoundBox()
{
    return sf::FloatRect(position.x, position.y, rect.getSize().x, rect.getSize().y);
}

sf::Vector2f Entity::getPosition()
{
    return position;
}