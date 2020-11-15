#include <iostream>
#include <SFML/Graphics.hpp>
#include <Square.h>
#ifndef PIECES_H
#define PIECES_H
using namespace sf;

class Pieces{
    public:
        vector<Square> possibleMoves;
        virtual vector<Square> getMoves(Square Cells[][8], int x, int y) = 0;
        int x, y;      
        bool isAlive;
        bool isWhite;
        Sprite piece;
};

#endif // PIECES_H
