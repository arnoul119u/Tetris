#include "game.hh"

Game::Game()
{
        win.create(sf::VideoMode(800, 600, 32), "Tetris");

        if (!music.openFromFile("ressources/sounds/tetris.ogg"))
        {
                std::cerr << "Error can't find Music" << std::endl;
        }
        this->getTetriminos("tetriminos");
        music.setLoop(true);
        music.setVolume(50.0);

        music.play();
}

Game::~Game()
{
        music.stop();
}

void Game::displayMenu()
{
        sf::Event event;

        Menu menu(win.getSize().x, win.getSize().y);
        while (win.isOpen())
        {
                while (win.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                                win.close();
                        if (event.type == sf::Event::KeyReleased)
                        {
                                if (event.key.code == sf::Keyboard::Up)
                                        menu.moveUp();
                                if (event.key.code == sf::Keyboard::Down)
                                        menu.moveDown();
                                if (event.key.code == sf::Keyboard::Return)
                                        menu.selectItem(*this);
                        }
                }
                win.clear();
                menu.draw(win);
                win.display();
        }
}

void Game::displaySettings()
{

}

void Game::launchGame()
{
        sf::Event event;
        this->printTetriminos();
        while (win.isOpen())
        {
                while (win.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                                win.close();
                        if (event.type == sf::Event::KeyReleased)
                        {
                                if (event.key.code == sf::Keyboard::BackSpace)
                                        return;
                                if (event.key.code == sf::Keyboard::P)
                                        this->toggleMusic();
                        }
                }
                win.clear();
                win.display();
        }
}
  #include <sys/stat.h>
       #include <fcntl.h>



int Game::getTetriminos(std::string path)
{
        DIR                       *ret;
        struct dirent             *l;
        Tetrimino tmp;
        std::ifstream file;
        std::vector<std::string>  lines;
        std::string line_tmp;
        std::vector<std::string>  first_line;
        int error;

        ret = opendir(path.c_str());
        nb_tetrimino = 0;
        if (!ret)
        {
                std::cerr << "Cannot access directory \"" << path << "\"" << std::endl;
                return (-1);
        }

        while((l = readdir(ret)))
        {
                error = 0;
                tmp.clear();
                if (l->d_type == DT_REG)
                {
                        file.open(path + "/" + l->d_name);
                        lines.clear();
                        if (file)
                                while (std::getline(file, line_tmp))
                                        lines.push_back(line_tmp);
                        else
                                std::cerr << "Cannot open the file " << l->d_name << std::endl;

                        file.close();
                        if (lines.size() <= 1)
                                error = 1;
                        else
                                first_line = split(lines[0]);

                        if (first_line.size() != 3)
                                error = 1;
                        if (error == 0)
                        {
                                tmp.setName(l->d_name);
                                tmp.setWidth(std::stoi(first_line[0]));
                                tmp.setHeight(std::stoi(first_line[1]));
                                tmp.setColor(std::stoi(first_line[2]));
                                if (!tmp.setShape(lines))
                                {
                                        ++nb_tetrimino;
                                        tetriminos.push_back(tmp);
                                }
                        }
                }
        }
        return (0);
}

void Game::printTetriminos() {
        std::cout << "Tetriminos :" << std::endl;
        for (unsigned int i = 0; i < tetriminos.size(); ++i) {
                std::cout << "\t" << tetriminos[i].getName() << " :" << std::endl;
                std::cout << "\t\tDimensions : [width = " << tetriminos[i].getWidth()
                          << " height = " << tetriminos[i].getHeight() << "]" << std::endl;
                std::cout << "\t\tColor : " << tetriminos[i].getColor() << std::endl;
                tetriminos[i].printShape();
        }
}

void Game::quit() {
        win.close();
}

void Game::toggleMusic()
{
        if (toggle_m)
                music.pause();
        else
                music.play();
        toggle_m = !toggle_m;
}
