#include "../header/openMenu.h"

OpenMenu::OpenMenu()
{
    openMenuBackGroundSprite.setTexture(*(Data::getInstance()->getOpenMenuImage()));
    openMenuBackGroundSprite.setScale(sf::Vector2f(1.8, 2.4));

    menu1.setFont(*(Data::getInstance()->getOpenMenuFont()));
    menu2.setFont(*(Data::getInstance()->getOpenMenuFont()));
    menu3.setFont(*(Data::getInstance()->getOpenMenuFont()));
    menu4.setFont(*(Data::getInstance()->getOpenMenuFont()));
}

OpenMenu::~OpenMenu()
{
}

int OpenMenu::Start(sf::RenderWindow &window)
{
    int controler = 1;

    menu1.setString("New Game");
    menu1.setPosition({580.f, 200.f});
    menu1.setCharacterSize(25);

    menu2.setString("Continue");
    menu2.setPosition({580.f, 260.f});
    menu2.setCharacterSize(25);

    menu3.setString("Ranking");
    menu3.setPosition({580.f, 320.f});
    menu3.setCharacterSize(25);

    menu4.setString("Exit");
    menu4.setPosition({580.f, 380.f});
    menu4.setCharacterSize(25);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                return -1;
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    controler--;
                    break;
                case sf::Keyboard::Down:
                    controler++;
                    break;
                // 1 - New Game
                // 2 - Continue Exist Game
                // 3 - Ranking Screen
                // 4 - Exit Game
                case sf::Keyboard::Return:
                    if (controler == 1)
                        if (!ShowNotImplementedYet(window))
                            return 1;
                        else
                            return -1;
                    // New Game
                    else if (controler == 2)
                        if (!ShowNotImplementedYet(window))
                            return 1;
                        else
                            return -1;
                    // Continue
                    else if (controler == 3)
                        if (!ShowNotImplementedYet(window))
                            return 1;
                        else
                            return -1;
                    // Ranking Screen
                    else
                        return -1;
                }
                // Nao deixando passar do limite da escolha
                if (controler < 1)
                    controler = 1;
                else if (controler > 4)
                    controler = 4;
            }
        }
        if (controler == 1)
        {
            menu1.setFillColor(sf::Color(255, 0, 0, 255));
            menu2.setFillColor(sf::Color(255, 255, 255, 255));
        }
        else if (controler == 2)
        {
            menu1.setFillColor(sf::Color(255, 255, 255, 255));
            menu2.setFillColor(sf::Color(255, 0, 0, 255));
            menu3.setFillColor(sf::Color(255, 255, 255, 255));
        }
        else if (controler == 3)
        {
            menu2.setFillColor(sf::Color(255, 255, 255, 255));
            menu3.setFillColor(sf::Color(255, 0, 0, 255));
            menu4.setFillColor(sf::Color(255, 255, 255, 255));
        }
        else
        {
            menu3.setFillColor(sf::Color(255, 255, 255, 255));
            menu4.setFillColor(sf::Color(255, 0, 0, 255));
        }

        window.clear();
        window.draw(openMenuBackGroundSprite);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.draw(menu4);
        window.display();
    }
}

int OpenMenu::ShowNotImplementedYet(sf::RenderWindow &window)
{
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
            switch (event.type)
            {
            case sf::Event::MouseButtonPressed:
            case sf::Event::KeyPressed:
                return 0;
            case sf::Event::Closed:
                return -1;
            }
    }
}