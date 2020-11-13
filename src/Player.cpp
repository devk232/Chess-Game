#include "Game.h"
#include "Pieces.h"
#include "Player.h"
#include <King.h>
#include "Queen.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include <string>
#include <iostream>
using namespace std;


Player::Player(int color) : playerColor(color){
    king = new King(color);
    queen = new Queen(color);
    for(int i = 0; i < 8; i++){
        pawn[i] = new Pawn(color);
    }
    for(int i = 0; i < 2; i++){
        bishop[i] = new Bishop(color);
        rook[i] = new Rook(color);
        knight[i] = new Knight(color);
    }
}

