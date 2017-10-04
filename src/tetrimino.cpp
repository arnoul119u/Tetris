#include "tetrimino.hh"

Tetrimino::Tetrimino(){
}

Tetrimino::Tetrimino(const Tetrimino& t) : name(t.name), shape(t.shape), width(t.width), height(t.height), color(t.color) {

}

Tetrimino::~Tetrimino() {
}

Tetrimino &Tetrimino::operator=(const Tetrimino& t){
  width = t.getWidth();
  height = t.getHeight();
  color = t.getColor();
  name = t.getName();
  shape = t.getShape();

  return (*this);
}

int Tetrimino::turnTetrimino() {
        return (0);
}

void Tetrimino::setName(std::string const& n) {
        name = n;
}

void Tetrimino::setWidth(unsigned int const& w) {
        width = w;
}

void Tetrimino::setHeight(unsigned int const& h) {
        height = h;
}

void Tetrimino::setColor(unsigned int const& c) {
        color = c;
}

int Tetrimino::setShape(std::vector<std::string> const &s){
        unsigned int i;
        unsigned int max;

        max = 0;
        if (s.size() - 1 > height)
                return (-1);
        i = -1;
        while (++i < s.size())
        {
                if (i && (max < s[i].size()))
                        max = s[i].size();
        }
        if (max != width)
                return (-1);
        i = 0;
        while (++i < s.size())
                (this->shape).push_back(s[i]);
        return (0);
}

void Tetrimino::printShape() {

        for (unsigned int i = 0; i < shape.size(); ++i)
                std::cout << shape[i] << std::endl;
}

std::string const& Tetrimino::getName() const {
        return (name);
}

unsigned int const& Tetrimino::getWidth() const {
        return (width);
}

unsigned int const& Tetrimino::getHeight() const {
        return (height);
}

unsigned int const& Tetrimino::getColor() const {
        return (color);
}
std::vector<std::string> const& Tetrimino::getShape() const{
  return (shape);
};

void Tetrimino::clear() {
        *this = Tetrimino();
}
