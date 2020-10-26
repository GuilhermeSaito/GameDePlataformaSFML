#include "../header/phaseManager.h"

PhaseManager::PhaseManager()
{
}

PhaseManager::~PhaseManager()
{
}

// Ainda tem que mexer aqui para fazer com que de para mudar da fase 1 para a fase 2
int PhaseManager::Start(sf::RenderWindow &window)
{
    while (true)
    {
        sf::Event event;
        if (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                return -1;
        window.clear();
        player1.Movimentation();
        player1.DrawPlayer1(window);
        window.display();
    }
}