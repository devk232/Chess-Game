#include <iostream>
#include "Game.h"
#include "Pieces.h"
#include "Pawn.h"

Pawn::Pawn(int color)
{
    isWhite = color;
    isAlive = true;
    blackPawn.loadFromFile("Textures/b_pawn.png");
    whitePawn.loadFromFile("Textures/w_pawn.png");
    x = (color == 0) ? 1 : 6;
    piece.setTexture((color == 0) ? blackPawn : whitePawn);
    occupied_value = -3;
}

vector<Square> Pawn::getMoves(Square cells[][8], int x, int y)
{
    possibleMoves.clear();
    if (cells[x][y].occupied_color == -1)
    {
        if(x == 1)
            if(cells[x + 2][y].occupied_color == 0)
                possibleMoves.push_back(cells[x + 2][y]);
        if (x != 7)
            if (cells[x + 1][y].occupied_value == 0 && cells[x + 1][y].occupied_color == 0)
                possibleMoves.push_back(cells[x + 1][y]);
        if (y != 0 && cells[x + 1][y - 1].occupied_color == 1)
            possibleMoves.push_back(cells[x + 1][y - 1]);
        if (y != 7 && cells[x + 1][y + 1].occupied_color == 1)
            possibleMoves.push_back(cells[x + 1][y + 1]);
    }
    if (cells[x][y].occupied_color == 1)
    {
        if(x == 6)
            if(cells[x - 2][y].occupied_color == 0)
                possibleMoves.push_back(cells[x - 2][y]);
        if (x != 0)
            if (cells[x - 1][y].occupied_value == 0 && cells[x - 1][y].occupied_color == 0)
                possibleMoves.push_back(cells[x - 1][y]);
        if (y != 0 && cells[x - 1][y - 1].occupied_color == -1)
            possibleMoves.push_back(cells[x - 1][y - 1]);
        if (y != 7 && cells[x - 1][y + 1].occupied_color == -1)
            possibleMoves.push_back(cells[x - 1][y + 1]);
    }
    return possibleMoves;
}