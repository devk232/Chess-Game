#ifndef PIECES_H
#define PIECES_H
#include <iostream>
#include<vector>
#include <Square.h>
using namespace std;

class Pieces{
    public:
        vector<Square> possibleMoves;
        virtual vector<Square> getMoves(Square Cells[][8], int x, int y) = 0;
        int x, y;      
        bool isAlive;
        bool isWhite;
};

#endif // PIECES_H
