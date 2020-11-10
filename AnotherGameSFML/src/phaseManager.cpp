#include "../header/phaseManager.h"

PhaseManager::PhaseManager()
{
}

PhaseManager::~PhaseManager()
{
}

// gameState:
// -1 = Exit app
// 1 = Phase1
// 2 = Phase2
// 3 = Save and go to openMenu

int PhaseManager::Start(sf::RenderWindow &window)
{

    gameState = 0;
    isPhase1 = true;
    while (true)
    {
        if (isPhase1)
        {
            // Só vai ser possível ir da phase 1 para a phase2, o contrário não vai ser possível
            phaseMapPath = "data/phaseMap/PhaseMap1.json";
            phaseMap.loadMapTileProprieties(phaseMapPath);
            collisionManager.setPhaseMapElement(&phaseMap);
            int option = Phase1(window);
            if (option == -1)
                return -1;
            else if (option == 2)
            {
                isPhase1 = false;
                clearEverything();
            }
            else if (option == 3)
                return 1;
            //else
            //clearEverthing();
            // clear Everthing and go to the next phase
        }
        else
        {
            phaseMapPath = "data/phaseMap/PhaseMap2.json";
            phaseMap.loadMapTileProprieties(phaseMapPath);
            collisionManager.setPhaseMapElement(&phaseMap);
            if (Phase2(window) == 3)
                return 1;
            return -1;
        }
    }
}

int PhaseManager::Phase1(sf::RenderWindow &window)
{
    while (true)
    {
        if (gameState == -1)
            return -1;
        else if (gameState == 2)
            return 2;
        else if (gameState == 3)
            return 3;

        update(window);
        render(window);

        // Chegando na parte da fase1 para mudar de fase
        if (player1.getPosition().x >= 130 * 32)
            gameState = 2;
    }
}

int PhaseManager::Phase2(sf::RenderWindow &window)
{
    while (true)
    {
        if (gameState == -1)
            return -1;
        else if (gameState == 3)
            return 3;

        update(window);
        render(window);
    }
}

void PhaseManager::update(sf::RenderWindow &window)
{
    collisionManager.setPlayerElement(&player1);
    sf::Event event;
    if (window.pollEvent(event))
    {
        // Window closed
        if (event.type == sf::Event::Closed)
            gameState = -1;
        //Key pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            gameState = escPressed(window);
        // DEPOIS PRECISA COLOCAR AQUI A OPCAO PARA DAR UM SAVE, QUE EH O gameState = 3
    }
    //std::cout << "Place Y Collision Manager: " << player1.getPosition().y << "\n";
    collisionManager.VerifyCollision();
    player1.Movimentation();
}

void PhaseManager::render(sf::RenderWindow &window)
{
    sf::View player1View(sf::Vector2f(player1.getPosition().x, 360), sf::Vector2f(1080, 720));
    window.setView(player1View);

    window.clear();
    player1.DrawPlayer1(window);
    phaseMap.draw(window);
    window.display();
}

int PhaseManager::escPressed(sf::RenderWindow &window)
{
    sf::View normalView(sf::Vector2f(560, 336), sf::Vector2f(1080, 720));
    window.setView(normalView);

    window.clear();
    sf::Sprite notImplementedYet;
    notImplementedYet.setTexture(*(Data::getInstance()->getNotImplementedYet()));
    notImplementedYet.setPosition(sf::Vector2f(window.getSize().x / 2 - 130, window.getSize().y / 2 - 130));
    window.draw(notImplementedYet);
    window.display();

    while (true)
    {
        sf::Event event;
        if (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::MouseButtonPressed:
            case sf::Event::KeyPressed:
                return 0;
            case sf::Event::Closed:
                return -1;
            }

            // Soh para teste, apagar isso depois
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
                return 3;
        }
    }
}

void PhaseManager::setIsPhaseOne(bool phase)
{
    isPhase1 = phase;
}

void PhaseManager::clearEverything()
{
    player1.setPosition({200, 500});
}

void PhaseManager::restartEverything()
{
    player1.setHp(100);
}