#include "../header/data.h"

Data *Data::dataInstance = NULL;

Data::Data()
{
    if (!openMenuImage.loadFromFile("data/imageOpenMenu.png"))
        EXIT_FAILURE;
    if (!player1Image.loadFromFile("data/Player1Image.png"))
        EXIT_FAILURE;
    if (!brickFloorTexture.loadFromFile("data/phaseMap/tilesUsed/BrickFloor.jpg"))
        EXIT_FAILURE;
    if (!iceFloorTexture.loadFromFile("data/phaseMap/tilesUsed/IceFloor.jpg"))
        EXIT_FAILURE;
    if (!iceFloor2Texture.loadFromFile("data/phaseMap/tilesUsed/IceFloor2.jpg"))
        EXIT_FAILURE;
    if (!purpleFloorTexture.loadFromFile("data/phaseMap/tilesUsed/PurpleFloor.jpg"))
        EXIT_FAILURE;

    if (!openMenuFont.loadFromFile("data/fonts/TurretRoad-Medium.ttf"))
        EXIT_FAILURE;

    if (!notImplementedYet.loadFromFile("data/notImplementedYet.png"))
        EXIT_FAILURE;
}

Data::~Data()
{
    delete dataInstance;
}

Data *Data::getInstance()
{
    if (!dataInstance)
        dataInstance = new Data;
    return dataInstance;
}

sf::Texture *Data::getOpenMenuImage()
{
    return &openMenuImage;
}

sf::Texture *Data::getPlayer1Texture()
{
    return &player1Image;
}

sf::Texture *Data::getBrickFloorTexture()
{
    return &brickFloorTexture;
}

sf::Texture *Data::getIceFloorTexture()
{
    return &iceFloorTexture;
}

sf::Texture *Data::getIceFloor2Texture()
{
    return &iceFloor2Texture;
}

sf::Texture *Data::getPurpleFloorTexture()
{
    return &purpleFloorTexture;
}

sf::Font *Data::getOpenMenuFont()
{
    return &openMenuFont;
}

sf::Texture *Data::getNotImplementedYet()
{
    return &notImplementedYet;
}