#ifndef BISHOP_H
#define BISHOP_H
#include <Pieces.h>

class Bishop: public Pieces
{
    public:
        Bishop(int color);
        vector<Square> getMoves(Square cells[][8], int x, int y);
    protected:

    private:
};

#endif // BISHOP_H
