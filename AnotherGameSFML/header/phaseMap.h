#pragma once

// draw phaseBackground and Tile
// load phaseMap from json file
#include "tile.h"
#include <iostream>
#include <vector>
#include <fstream>

class PhaseMap
{
private:
    std::vector<std::vector<Tile *>> tileMap;
    int alturaMax;
    int larguraMax;

public:
    PhaseMap();
    ~PhaseMap();

    // false = error
    bool loadMapTileProprieties(std::string path);
    bool draw(sf::RenderWindow &window);

    void clearMatrix();

    std::vector<std::vector<Tile *>> getMatrixTile();
    Tile *getTile(int posX, int posY);
    bool isValidTile(int i, int j);
};