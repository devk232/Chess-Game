#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
label:
    sf::RenderWindow window(sf::VideoMode(1100, 800), "The Chess", sf::Style::Titlebar | sf::Style::Close);
    Game chess(sf::Color(0xf3bc7aff), sf::Color(0xae722bff));
    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
            if (e.type == sf::Event::MouseButtonPressed)
            {
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    if (e.mouseButton.x >= 0 && e.mouseButton.x <= 800 && e.mouseButton.y >= 0 && e.mouseButton.y <= 800)
                    {
                        int x = e.mouseButton.y / 100, y = e.mouseButton.x / 100;
                        if (!chess.getSelected() && chess.isOver == false)
                        {
                            chess.SelectPiece(chess.cells, x, y);
                        }
                        else
                        {
                            chess.moveSelected(chess.cells, e.mouseButton.y / 100, e.mouseButton.x / 100);
                        }
                    }
                    if (e.mouseButton.x >= 850 && e.mouseButton.x <= 1024 && e.mouseButton.y >= 5 && e.mouseButton.y <= 55)
                    {
                        goto label;
                    }
                }
            }
        }
        window.draw(chess);
        window.display();
    }
    return 0;
}
