
#ifndef BOARD_H
#define BOARD_H

class Board
{
    public:
        Board();
        void showBoard();
        void initialiseBoard();
    private:
        int cells[8][8];  // 0 if unoccupied and 1 if occupied
        
};

#endif 
