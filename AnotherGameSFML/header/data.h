#pragma once

#include <SFML/Graphics.hpp>

class Data
{
private:
    Data();
    static Data *dataInstance;

    sf::Texture openMenuImage;
    sf::Texture playerRightImage;
    sf::Texture playerLeftImage;

    sf::Font openMenuFont;

    sf::Texture notImplementedYet;

public:
    static Data *getInstance();
    ~Data();

    sf::Texture *getOpenMenuImage();
    sf::Texture *getPlayerRightImage();
    sf::Texture *getPlayerLeftImage();
    sf::Font *getOpenMenuFont();

    sf::Texture *getNotImplementedYet();
};