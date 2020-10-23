#pragma once

#include <SFML/Graphics.hpp>

class Data
{
private:
    Data();
    static Data *dataInstance;

    sf::Texture openMenuImage;

    sf::Font openMenuFont;

    sf::Texture notImplementedYet;

public:
    static Data *getInstance();
    ~Data();

    sf::Texture *getOpenMenuImage();
    sf::Font *getOpenMenuFont();

    sf::Texture *getNotImplementedYet();
};