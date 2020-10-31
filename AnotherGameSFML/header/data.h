#pragma once

#include <SFML/Graphics.hpp>

class Data
{
private:
    Data();
    static Data *dataInstance;

    sf::Texture openMenuImage;
    sf::Texture player1Image;
    sf::Texture brickFloorTexture;
    sf::Texture iceFloorTexture;
    sf::Texture iceFloor2Texture;
    sf::Texture purpleFloorTexture;

    sf::Font openMenuFont;

    sf::Texture notImplementedYet;

public:
    static Data *getInstance();
    ~Data();

    sf::Texture *getOpenMenuImage();
    sf::Texture *getPlayer1Texture();
    sf::Texture *getBrickFloorTexture();
    sf::Texture *getIceFloorTexture();
    sf::Texture *getIceFloor2Texture();
    sf::Texture *getPurpleFloorTexture();

    sf::Font *getOpenMenuFont();

    sf::Texture *getNotImplementedYet();
};