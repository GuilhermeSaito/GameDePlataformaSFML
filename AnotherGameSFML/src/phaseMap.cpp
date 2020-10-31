#include "../header/phaseMap.h"

// To use the json
#include "../nlohmann/json.hpp"
using json = nlohmann::json;

PhaseMap::PhaseMap()
{
}

PhaseMap::~PhaseMap()
{
    clearMatrix();
}

bool PhaseMap::loadMapTileProprieties()
{
    // temp path
    std::string path = "data/phaseMap/PhaseMap.json";
    std::ifstream in(path);
    if (!in.good())
    {
        std::cout << "Não foi possivel abrir o " << path << std::endl;
        return false;
    }
    std::cout << path << "\tLoaded" << std::endl;

    clearMatrix();

    json jMap;
    in >> jMap;

    alturaMax = jMap["height"];
    larguraMax = jMap["width"];

    // Carregando as propriedades de cada tile da fase e construindo a matriz de tile (o mapa).
    for (int j = 0; j < alturaMax; j++)
    {
        std::vector<Tile *> tileLinha;
        for (int i = 0; i < larguraMax; i++)
        {
            int tilePropriedade = jMap["layers"][0]["data"][j * larguraMax + i];
            tileLinha.push_back(new Tile(tilePropriedade, i * 32, j * 32));
        }
        tileMap.push_back(tileLinha);
    }

    in.close();
}

bool PhaseMap::draw(sf::RenderWindow &window)
{
    // Fazer desenhar em cada local, desenhando a fase inteira.
    for (std::vector<Tile *> i : tileMap)
        for (Tile *j : i)
            j->draw(window);
}

void PhaseMap::clearMatrix()
{
    for (std::vector<Tile *> i : tileMap)
        for (Tile *j : i)
            delete j;
    tileMap.clear();
}

std::vector<std::vector<Tile *>> PhaseMap::getMatrixTile()
{
    return tileMap;
}

Tile *PhaseMap::getTile(int posX, int posY)
{
    // vai de 0 a 21 (altura)    e 0 a 175 (largura).
    return tileMap[posY][posX];
}

bool PhaseMap::isValidTile(int i, int j)
{
    if (((i >= 0) && (i <= larguraMax)) && ((j >= 0) && (j <= alturaMax)))
        return true;
    return false;
}