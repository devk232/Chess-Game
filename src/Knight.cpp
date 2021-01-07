#include <iostream>
#include <vector>
#include "Square.h"
#include "Pieces.h"
#include "Knight.h"
using namespace std;

Knight::Knight(int color)
{
    isWhite = color;
    isAlive = true;
    blackKnight.loadFromFile("Textures/b_knight.png");
    whiteKnight.loadFromFile("Textures/w_knight.png");
    x = (color == 0) ? 0 : 7;
    occupied_value = -1;
    piece.setTexture((color == 0) ? blackKnight : whiteKnight);
}

std::vector<Square> Knight::getMoves(Square Cells[][8], int x, int y)
{
    possibleMoves.clear();
    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1}; // all possible moves.
    int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2}; // all possible moves.
    for (int i = 0; i < 8; i++)
    {
        if (x + dx[i] > 7 || x + dx[i] < 0)
        {
            continue;
        }
        if (y + dy[i] > 7 || y + dy[i] < 0)
        {
            continue;
        }
        if (Cells[x + dx[i]][y + dy[i]].occupied_color == Cells[x][y].occupied_color)
            continue;
        possibleMoves.push_back(Cells[x + dx[i]][y + dy[i]]);
       // std::cout << Cells[x + dx[i]][y + dy[i]].x << std::endl;
    }
    return possibleMoves;
}