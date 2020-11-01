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
    collisionManager.setElements(&player1, &phaseMap);
    phaseMap.loadMapTileProprieties();
    while (true)
    {
        sf::Event event;
        if (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                return -1;
        collisionManager.StartVerifyCollision();
        sf::View player1View(sf::Vector2f(player1.getPosition().x, 360), sf::Vector2f(1080, 720));
        window.setView(player1View);
        window.clear();
        player1.Movimentation();
        player1.DrawPlayer1(window);
        phaseMap.draw(window);
        window.display();
    }
}