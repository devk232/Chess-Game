#include <iostream>
#include "Game.h"
#include "Pieces.h"
#include "Bishop.h"
using namespace std;

Bishop::Bishop(int color){
    isWhite = color;
    isAlive  = true;
}
vector<Square> Bishop::getMoves(Square cells[][8], int x, int y){
    possibleMoves.clear();
    int a = x + 1, b = y + 1;
    while(a <= 7 && b <= 7){
        if(cells[a][b].occupied_value == 0)
            possibleMoves.push_back(cells[x][y]);
        else if(cells[a][b].occupied_color == cells[x][y].occupied_color)
            break;
        else{
            possibleMoves.push_back(cells[a][b]);
            break;
        }
        a++; b++;
    }
    a = x + 1, b = y - 1;
    while(a <= 7 && b >= 0){
        if(cells[a][b].occupied_value == 0)
            possibleMoves.push_back(cells[x][y]);
        else if(cells[a][b].occupied_color == cells[x][y].occupied_color)
            break;
        else{
            possibleMoves.push_back(cells[a][b]);
            break;
        }
        a++; b--;
    }
    a = x - 1, b = y - 1;
    while(a >= 0 && b >= 0){
        if(cells[a][b].occupied_value == 0)
            possibleMoves.push_back(cells[x][y]);
        else if(cells[a][b].occupied_color == cells[x][y].occupied_color)
            break;
        else{
            possibleMoves.push_back(cells[a][b]);
            break;
        }
        a--; b--;
    }
    a = x - 1, b = y + 1;
    while(a >= 0 && b <= 7){
        if(cells[a][b].occupied_value == 0)
            possibleMoves.push_back(cells[x][y]);
        else if(cells[a][b].occupied_color == cells[x][y].occupied_color)
            break;
        else{
            possibleMoves.push_back(cells[a][b]);
            break;
        }
        a--; b++;
    }
    return possibleMoves;
}