#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Pieces.h"
#include <Square.h>
using namespace sf;

Game::Game(Color c1, Color c2): player1(1), player2(0){
   for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cells[i][j].square.setPosition(Vector2f(j*100.0f, i*100.0f));
            cells[i][j].square.setSize(Vector2f(100.f, 100.f)); 
            cells[i][j].square.setFillColor((i + j)%2 ? c2 : c1);
        }
    }
}
void Game::DrawBoard(Color col1, Color col2){

}
void Game::Start(){

}