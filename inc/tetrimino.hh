#ifndef __TETRIMINO_HH__
#define __TETRIMINO_HH__

#include <string>
#include <dirent.h>
#include "tetris.h"

class Tetrimino
{
  public:
    Tetrimino();
    Tetrimino(const Tetrimino&);
    ~Tetrimino();
    Tetrimino &operator=(const Tetrimino&);

    int turnTetrimino();
    void printShape();

    void setName(std::string const&);
    void setWidth(unsigned int const&);
    void setHeight(unsigned int const&);
    void setColor(unsigned int const&);
    int setShape(std::vector<std::string> const&);

    std::string const& getName() const;
    unsigned int const& getWidth() const;
    unsigned int const& getHeight() const;
    unsigned int const& getColor() const;
    std::vector<std::string> const& getShape() const;
    void clear();

  protected:
    std::string name;
    std::vector<std::string> shape;
    unsigned int         width;
    unsigned int         height;
    unsigned int         color;
};

#endif
