#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "tetrimino.hh"
#include "menu.hh"
#include "game.hh"

int main(int ac, char **av)
{
        Game game;
        game.displayMenu();
        (void) ac;
        (void) av;
        return (0);
}
