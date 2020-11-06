#include "Board.h"

Board::Board(){
   for(int i = 0; i < 8; i++){
       for(int j = 0; j < 8; j++){
           cells[i][j] = 0;                    // seting all cells to unoccupied initially.
       }
   }
}

void Board::initialiseBoard(){
    for(int i = 0; i < 8; i++){
        cells[0][i] = 1;
        cells[1][i] = 1; 
        cells[6][i] = 1; 
        cells[7][i] = 1; 
    }
    for(int i = 0; i < 8; i++){
        
    }
}