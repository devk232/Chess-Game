#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Pieces.h"
#include "Queen.h"
using namespace std;

Queen::Queen(){
    
}

bool Queen::CheckMove(int x, int y, int x1, int y1){
    if(x != x1 || y != y1 || (x - x1) != (y - y1))
        return false;
    if(x == x1){
        for(int i = y + 1; i < y1; i += (x1 > x? 1: -1)){
            // check if there is a piece in between 
           if(1){
            return false;
           }
        }
        return true;
    }
    if(y == y1){
        for(int i = x + 1; i < x1; i += (x1 > x? 1: -1)){
            // cheeck for piece
            if(1){
            return false;
            }
        }
        return true;
    }
    else{
        for(int a = 0, b = 0; a < abs(x - x1); a += (x1 > x? 1: -1), b += (x1 > x? 1: -1)){
            // check for a piece at a,b
            if(1){
            return false;
            }
            return true;
        } 
    }
}
