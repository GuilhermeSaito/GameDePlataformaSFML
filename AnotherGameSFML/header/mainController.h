#pragma once

#include "openMenu.h"

class MainController
{
private:
    sf::RenderWindow window;
    OpenMenu openMenu;
    void Start();

public:
    MainController();
    ~MainController();
};