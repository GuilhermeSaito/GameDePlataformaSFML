#pragma once

// Aqui que vai ser o centro do Jogo, ele que vai organizar a transicao de Telas

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