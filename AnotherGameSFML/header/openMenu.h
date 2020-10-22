#pragma once

#include "data.h"

class OpenMenu
{
private:
    sf::Sprite backGroundEraseSprite;

public:
    OpenMenu();
    ~OpenMenu();

    void Start(sf::RenderWindow &window);
};