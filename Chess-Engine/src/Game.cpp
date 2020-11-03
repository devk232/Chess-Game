#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Board.h"
#include "Pieces.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
using namespace sf;
using namespace std;

Game::Game()
{
    //ctor
}

void Game::initialize(){
    sf::RenderWindow window(sf::VideoMode(512,512), "Chess");
}
