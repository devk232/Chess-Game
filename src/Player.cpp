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
    for(int i = 0; i < 8;i++){
        pawn[i]->x = i;
        pawn[i]->piece.setPosition(pawn[i]->x*100.f, pawn[i]->y*100.f);
    }
    bishop[0]->x = 2; bishop[1]->x = 5;
    rook[0]->x = 0; rook[1]->x = 7;
    knight[0]->x = 1; knight[1]->x = 6;
    for(int i = 0; i < 2; i++){
        bishop[i]->piece.setPosition(100.0f*bishop[i]->x, 100.0f*bishop[i]->y);
        knight[i]->piece.setPosition(100.0f*knight[i]->x, 100.0f*knight[i]->y);
        rook[i]->piece.setPosition(100.0f*rook[i]->x, 100.0f*rook[i]->y);
        bishop[i]->piece.setOrigin(50.0f*bishop[i]->x, 50.0f*bishop[i]->y);
        knight[i]->piece.setOrigin(50.0f*knight[i]->x, 50.0f*knight[i]->y);
        rook[i]->piece.setOrigin(50.0f*rook[i]->x, 50.0f*rook[i]->y);
    }
}

