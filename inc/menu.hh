#ifndef __MENU_HH__
#define __MENU_HH__

#include <SFML/Graphics.hpp>
#include <iostream>
#include "tetris.h"
#include "game.hh"

#define	MAX_ITEMS 3

class Menu
{
public:
  Menu(float width, float height);
  ~Menu();

  void	draw(sf::RenderWindow &win);
  void	moveUp();
  void	moveDown();
  void  selectItem(class Game &g);

private:
  int		    selected;
  sf::Font	font;
  sf::Text	items[MAX_ITEMS];
};


#endif
