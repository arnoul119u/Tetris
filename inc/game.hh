#ifndef __GAME_HH__
#define __GAME_HH__

#include <iostream>
#include <fstream>
#include "menu.hh"
#include "tetrimino.hh"
#include "tetris.h"

class Game
{
public:
  Game();
  ~Game();

  void toggleMusic();
  void displayMenu();
  void displaySettings();
  void launchGame();

  int  getTetriminos(std::string);
  void  printTetriminos();

  void quit();

protected:
  sf::RenderWindow               win;
  sf::Music                      music;
  int                            toggle_m;

  std::vector<Tetrimino>         tetriminos;
  int                            nb_tetrimino;
};

#endif
