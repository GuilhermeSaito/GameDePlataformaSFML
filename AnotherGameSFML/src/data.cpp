#include "../header/data.h"

Data *Data::dataInstance = NULL;

Data::Data()
{
    if (!openMenuImage.loadFromFile("data/imageOpenMenu.png"))
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

sf::Font *Data::getOpenMenuFont()
{
    return &openMenuFont;
}

sf::Texture *Data::getNotImplementedYet()
{
    return &notImplementedYet;
}