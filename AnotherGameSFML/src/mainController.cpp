#include "../header/mainController.h"

MainController::MainController()
{
    Start();
}

MainController::~MainController()
{
}

void MainController::Start()
{
    window.create(sf::VideoMode(780, 1080), "Arudina's Game");
    openMenu.Start(window);
    window.close();
}