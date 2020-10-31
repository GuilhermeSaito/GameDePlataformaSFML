#include "../header/tileManager.h"

TileManager::TileManager()
{
}

TileManager::~TileManager()
{
}

sf::Texture *TileManager::getTileTexture(int tileType, sf::RectangleShape &rect, sf::Vector2f spaceOcuped)
{
    switch (tileType)
    {
    case BrickFloor:
        rect.setSize(sf::Vector2f(32, 32));
        rect.setPosition(spaceOcuped);
        return Data::getInstance()->getBrickFloorTexture();
        break;
    case IceFloor:
        rect.setSize(sf::Vector2f(32, 32));
        rect.setPosition(spaceOcuped);
        return Data::getInstance()->getIceFloorTexture();
        break;
    case IceFloor2:
        rect.setSize(sf::Vector2f(32, 32));
        rect.setPosition(spaceOcuped);
        return Data::getInstance()->getIceFloor2Texture();
        break;
    case PurpleFloor:
        rect.setSize(sf::Vector2f(32, 32));
        rect.setPosition(spaceOcuped);
        return Data::getInstance()->getPurpleFloorTexture();
        break;
        /*case Spike:
        rect.setSize(sf::Vector2f(32, 32));
        rect.setPosition(spaceOcuped);
        return Data::getInstance()->getSpikeTrap();
        break;*/
    }
}