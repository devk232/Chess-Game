#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Pieces.h"
#include "Player.h"

using namespace sf;

int main(){
    RenderWindow window(VideoMode(1100, 800), "The Chess", Style::Titlebar | Style::Close);
    Game chess(Color(0xf3bc7aff),Color(0xae722bff));
    Bishop p(1);
    Player p2(0);
    while(window.isOpen()){
        Event e;
        while(window.pollEvent(e)){
            if(e.type == Event::Closed)
                window.close();
            if(e.type == Event::MouseButtonPressed){

            }
        }
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                window.draw(chess.cells[i][j].square);
            }
        }
        window.draw(p.piece);
        window.display();
    }
    return 0;
}
