#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include "Game.h"
#include "Pieces.h"
#include "Player.h"
#include <King.h>
#include "Queen.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
using namespace sf;


Player::Player(int color) : playerColor(color){
    
}
