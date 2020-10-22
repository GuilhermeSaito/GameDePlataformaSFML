#include "../header/data.h"

Data *Data::dataInstance = NULL;

Data::Data()
{
    if (!backGroundErase.loadFromFile("data/erase.png"))
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

sf::Texture *Data::getBackGroundErase()
{
    return &backGroundErase;
}