#pragma once

#include "data.h"

class OpenMenu
{
private:
    sf::Sprite openMenuBackGroundSprite;

    sf::Text menu1;
    sf::Text menu2;
    sf::Text menu3;
    sf::Text menu4;

public:
    OpenMenu();
    ~OpenMenu();

    int Start(sf::RenderWindow &window);
    int ShowCharacterSelection(sf::RenderWindow &window);

    int ShowNotImplementedYet(sf::RenderWindow &window);
};