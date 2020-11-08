#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Pieces.h"
#include "Queen.h"
using namespace std;

vector<Square> Queen::getMoves(Square cells[][8], int x, int y){
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
        int r = x - 1;
    while(r >= 0){
        if(cells[r][y].occupied_value == 0)
            possibleMoves.push_back(cells[r][y]);
        else if(cells[r][y].occupied_color = cells[x][y].occupied_color)
            break;
        else if(cells[r][y].occupied_color != cells[x][y].occupied_color){
            possibleMoves.push_back(cells[r][y]);
            break;
        }
        r--;
    }
    r = x + 1;
    while(r <= 7){
        if(cells[r][y].occupied_value == 0)
            possibleMoves.push_back(cells[r][y]);
        else if(cells[r][y].occupied_color = cells[x][y].occupied_color)
            break;
        else if(cells[r][y].occupied_color != cells[x][y].occupied_color){
            possibleMoves.push_back(cells[r][y]);
            break;
        }
        r++;
    }
    r = y - 1;
    while(r >= 0){
        if(cells[x][r].occupied_value == 0)
            possibleMoves.push_back(cells[x][r]);
        else if(cells[x][r].occupied_color = cells[x][y].occupied_color)
            break;
        else if(cells[x][r].occupied_color != cells[x][y].occupied_color){
            possibleMoves.push_back(cells[x][r]);
            break;
        }
        r--;
    }
    r = y + 1;
    while(r <= 7){
        if(cells[x][r].occupied_value == 0)while(r >= 0){
        if(cells[x][r].occupied_value == 0)
            possibleMoves.push_back(cells[x][r]);
        else if(cells[x][r].occupied_color = cells[x][y].occupied_color)
            break;
        else if(cells[x][r].occupied_color != cells[x][y].occupied_color){
            possibleMoves.push_back(cells[x][r]);
              break;
        }
        r++;
    }
    return possibleMoves;
}