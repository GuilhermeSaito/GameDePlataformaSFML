#pragma once

#include <SFML/Graphics.hpp>

class Data
{
private:
    Data();
    static Data *dataInstance;

    sf::Texture backGroundErase;

public:
    static Data *getInstance();
    ~Data();

    sf::Texture *getBackGroundErase();
};