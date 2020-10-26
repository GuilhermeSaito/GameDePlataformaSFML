#include "../header/mainController.h"

MainController::MainController()
{
    Start();
}

MainController::~MainController()
{
}

// Controle de Telas
void MainController::Start()
{
    int controler = 1;
    window.create(sf::VideoMode(1080, 720), "Arudina's Game");
    while (controler != -1)
    {
        if (controler == 1)
            controler = openMenu.Start(window);
        else if (controler == 2)
            controler = phaseManager.Start(window);
    }
    window.close();
}