#include <iostream>
#include "Game.h"
#include "Pieces.h"
#include <vector>
#include "Rook.h"
using namespace std;

Rook::Rook(int color)
{
    isWhite = color;
    isAlive = true;
    blackRook.loadFromFile("Textures/b_rook.png");
    whiteRook.loadFromFile("Textures/w_rook.png");
    occupied_value = 1;
    x = (color == 0) ? 0 : 7;
    piece.setTexture((color == 0) ? blackRook : whiteRook);
}

vector<Square> Rook::getMoves(Square cells[][8], int x, int y)
{
    possibleMoves.clear();
    int r = x - 1;
    while (r >= 0)
    {
        if (cells[r][y].occupied_value == 0)
            possibleMoves.push_back(cells[r][y]);
        else if (cells[r][y].occupied_color == cells[x][y].occupied_color)
            break;
        else if (cells[r][y].occupied_color != cells[x][y].occupied_color)
        {
            possibleMoves.push_back(cells[r][y]);
            break;
        }
        r--;
    }
    r = x + 1;
    while (r <= 7)
    {
        if (cells[r][y].occupied_value == 0)
            possibleMoves.push_back(cells[r][y]);
        else if (cells[r][y].occupied_color == cells[x][y].occupied_color)
            break;
        else if (cells[r][y].occupied_color != cells[x][y].occupied_color)
        {
            possibleMoves.push_back(cells[r][y]);
            break;
        }
        r++;
    }
    r = y - 1;
    while (r >= 0)
    {
        if (cells[x][r].occupied_value == 0)
            possibleMoves.push_back(cells[x][r]);
        else if (cells[x][r].occupied_color == cells[x][y].occupied_color)
            break;
        else if (cells[x][r].occupied_color != cells[x][y].occupied_color)
        {
            possibleMoves.push_back(cells[x][r]);
            break;
        }
        r--;
    }
    r = y + 1;
    while (r <= 7)
    {
        if (cells[x][r].occupied_value == 0)
            possibleMoves.push_back(cells[x][r]);
        else if (cells[x][r].occupied_color == cells[x][y].occupied_color)
            break;
        else if (cells[x][r].occupied_color != cells[x][y].occupied_color)
        {
            possibleMoves.push_back(cells[x][r]);
            break;
        }
        r++;
    }
    return possibleMoves;
}