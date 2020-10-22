#include "../header/openMenu.h"

OpenMenu::OpenMenu()
{
    backGroundEraseSprite.setTexture(*(Data::getInstance()->getBackGroundErase()));
}

OpenMenu::~OpenMenu()
{
}

void OpenMenu::Start(sf::RenderWindow &window)
{
    while (window.isOpen())
    {
        sf::Event event;
        if (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                return;
        window.clear();
        window.draw(backGroundEraseSprite);
        window.display();
    }
}