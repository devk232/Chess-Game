#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <King.h>
#include "Pieces.h"
#include "Queen.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
using namespace std;
class Player
{
    public:
        Player(int color);
        void getMove();   
        int playerColor;             // 0 if player is black, 1 otherwise.   
    private:
        string move;                
        // each player has the following pieces.
        King* king;                          
        Queen* queen;
        Bishop* bishop[2];
        Rook* rook[2];
        Knight* knight[2];
        Pawn* pawn[8];
};

#endif 