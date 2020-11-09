#ifndef PIECES_H
#define PIECES_H
#include <iostream>
#include<vector>
#include "Square.h"
using namespace std;

class Pieces{
    public:
        Pieces();
        Pieces(bool color);
        virtual vector<Square> getMoves(Square Cells[][8], int x, int y);
    protected:
        vector<Square> possibleMoves;
        int x, y;      // to see the position of a piece
        bool isAlive;
        bool isWhite;
};

#endif // PIECES_H
