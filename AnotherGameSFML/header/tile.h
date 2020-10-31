#pragma once

// Set the sprite of the Tiles
// Set the Collision local
#include "tileManager.h"

class Tile
{
private:
    TileManager tileManager;

    int numProprietieTile;

    sf::RectangleShape rectTile;
    sf::Sprite tileSprite;
    // Como esse spaceOcuped é o local ond está localizado no desenho do SFML, para achar no vetor,
    // Simplesmente divide por 32;
    sf::Vector2f spaceOcuped;

public:
    Tile(int numTile, int spaceOcupedX, int spaceOcupedY);
    ~Tile();

    void draw(sf::RenderWindow &window);

    sf::FloatRect getBoundBox();

    sf::Vector2f getPosition();

    int getNumTile();
};