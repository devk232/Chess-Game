#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

int main(){
    RenderWindow window(VideoMode(1100, 800), "The Chess", Style::Titlebar | Style::Close);
    Game chess(Color(0xf3bc7aff),Color(0xae722bff));
    while(window.isOpen()){
        Event e;
        while(window.pollEvent(e)){
            if(e.type == Event::Closed)
                window.close();
            if(e.type == Event::MouseButtonPressed){
                if(e.mouseButton.button == sf::Mouse::Left){
                    if(e.mouseButton.x >= 0 && e.mouseButton.x <= 800 && e.mouseButton.y >= 0 && e.mouseButton.y <= 800){ 
                        cout << e.mouseButton.x << " " << e.mouseButton.y  << endl;  
                        int x = e.mouseButton.y/100, y = e.mouseButton.x/100;
                        cout << x << " " << y << endl;          
                        if(!chess.getSelected())
                            chess.SelectPiece(chess.cells,x, y);
                        // else
                        //    chess.moveSelected(chess.cells,x,y);
                    }
                }
            }
        }
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                window.draw(chess.cells[i][j].square);
            }
        }
        window.draw(chess);
        window.display();
    }
    return 0;
}
