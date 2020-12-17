#ifndef PIECES_H
#define PIECES_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Square.h"
using namespace std;

class Pieces
{
public:
    vector<Square> possibleMoves;
    virtual vector<Square> getMoves(Square Cells[][8], int x, int y) = 0;
    int x, y;
    bool isAlive;
    bool isWhite;
    bool occupied_color;
    int occupied_value;
    sf::Sprite piece;
};

#endif // PIECES_H
