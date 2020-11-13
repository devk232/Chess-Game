#ifndef QUEEN_H
#define QUEEN_H
#include <Pieces.h>

class Queen: public Pieces
{
    public:
        Queen(int);
        vector<Square> getMoves(Square cells[][8], int x, int y);
    protected:

    private:
};

#endif // QUEEN_H
