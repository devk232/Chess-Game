#include <iostream>
#include "Square.h"
#include "Pieces.h"
#include "Knight.h"
using namespace std;

Knight::Knight(int color){
    isWhite = color;
    isAlive = true;
}

vector<Square> Knight::getMoves(Square Cells[][8], int x, int y){
    possibleMoves.clear();
    int dx[] = {2, 2,-2,-2,1, 1,-1, -1};    // all possible moves.
    int dy[] = {1,-1, 1,-1, 2,-2, 2,-2};    // all possible moves.
    for(int i = 0; i < 8; i++){
        if(x + dx[i] > 7 || x + dx[i] < 0)
            continue;
        if(y + dy[i] > 7 || y + dy[i] < 0)
            continue;
        possibleMoves.push_back(Cells[x + dx[i]][y + dy[i]]);
    }
}