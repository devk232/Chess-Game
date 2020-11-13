#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Pieces.h"
using namespace sf;

Game::Game(): player1(1), player2(0){
    
}
void Game::Start(){
    RenderWindow window(VideoMode(1024, 453), "The Chess");
    while(window.isOpen()){
        Event e;

    }
}