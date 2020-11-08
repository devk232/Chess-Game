#ifndef PAWN_H
#define PAWN_H
#include <iostream>
#include <vector>
#include <Square.h>
using namespace std;

class Pawn: public Pieces{
    public:
        vector<Square> getMoves(Square cells[][8], int x, int y);
    protected:
};

#endif // PAWN_H
