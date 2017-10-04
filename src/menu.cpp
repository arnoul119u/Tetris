#include "menu.hh"

Menu::Menu(float width, float height)
{
        if (!font.loadFromFile("ressources/fonts/arial.ttf"))
                std::cerr << "Font not found" << std::endl;
        selected = 0;
        items[0].setFont(font);
        items[0].setFillColor(sf::Color::Blue);
        items[0].setString("Play");
        items[0].setPosition(sf::Vector2f((width / 2.0) - (items[0].getGlobalBounds().width / 2.0), height / (MAX_ITEMS + 1) * 1));

        items[1].setFont(font);
        items[1].setFillColor(sf::Color::White);
        items[1].setString("Settings");
        items[1].setPosition(sf::Vector2f((width / 2.0) - (items[1].getGlobalBounds().width / 2.0), height / (MAX_ITEMS + 1) * 2));

        items[2].setFont(font);
        items[2].setFillColor(sf::Color::White);
        items[2].setString("Quit");
        items[2].setPosition(sf::Vector2f((width / 2.0) - (items[2].getGlobalBounds().width / 2.0), height / (MAX_ITEMS + 1) * 3));
}

Menu::~Menu(){

}

void Menu::draw(sf::RenderWindow &win)
{
        int i;

        i = -1;
        while (++i < MAX_ITEMS)
                win.draw(items[i]);
}

void Menu::moveUp()
{
        if (selected - 1 >= 0)
        {
                items[selected].setFillColor(sf::Color::White);
                items[--selected].setFillColor(sf::Color::Blue);
        }
}

void Menu::moveDown()
{
        if (selected + 1 < MAX_ITEMS)
        {
                items[selected].setFillColor(sf::Color::White);
                items[++selected].setFillColor(sf::Color::Blue);
        }
}

void Menu::selectItem(Game &game)
{
        if (selected == 0)
        {
                std::cerr << "Play game" << std::endl;
                game.launchGame();
        }
        if (selected == 1)
                std::cerr << "Settings" << std::endl;
        if (selected == 2)
        {
                std::cerr << "Quit" << std::endl;
                game.quit();
        }
}
