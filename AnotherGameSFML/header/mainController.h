#pragma once

// Aqui que vai ser o centro do Jogo, ele que vai organizar a transicao de Telas

// OpenMenu Stantiated here
// PhaseManager Stantiated here
#include "openMenu.h"
#include "phaseManager.h"

class MainController
{
private:
    sf::RenderWindow window;

    OpenMenu openMenu;
    PhaseManager phaseManager;

    void Start();

public:
    MainController();
    ~MainController();
};