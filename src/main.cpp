#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Pieces.h"
#include "Player.h"

using namespace sf;

int main(){
    Game game;
    RenderWindow window(VideoMode(1000, 800), "The Chess", Style::Titlebar | Style::Close);
    window.setVerticalSyncEnabled(true);
    while(window.isOpen()){
        Event e;
        while(window.pollEvent(e)){
            if(e.type == Event::Closed)
                window.close();
            if(e.type == Event::MouseButtonPressed){
                if(e.mouseButton.button == Mouse::Left){
                    
                }
            }
        }
        window.display();
    }
    return 0;
}
