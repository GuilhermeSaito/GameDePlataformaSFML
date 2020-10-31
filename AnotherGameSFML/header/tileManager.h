#pragma once

// Set the texture in the specific tile
// Set the position of the tile
#include "data.h"

class TileManager
{
private:
    // Se for utilizar outros Tiles, soh adicionar ou Remover daqui, e mexer no cpp
    enum TileType
    {
        BrickFloor = 1,
        IceFloor = 2,
        IceFloor2 = 3,
        PurpleFloor = 4,
        //Spike = 5
    };

public:
    TileManager();
    ~TileManager();

    sf::Texture *getTileTexture(int tileType, sf::RectangleShape &rect, sf::Vector2f spaceOcuped);
};