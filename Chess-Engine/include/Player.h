#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <King.h>
#include <Knight.h>
#include <Pawn.h>
#include <Queen.h>
#include <Bishop.h>
#include <Rook.h>
using namespace std;
class Player
{
    public:
        Player();
        Player(int color);
        void getMove();   
        int playerColor;             // 0 if player is black, 1 otherwise.   
    private:
        string move;                
        // each player has the following pieces.
        King king;                          
        Queen queen;
        Bishop bishop[2];
        Rook rook[2];
        Knight knight[2];
        Pawn paws[8];
};

#endif 