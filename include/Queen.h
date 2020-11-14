#ifndef QUEEN_H
#define QUEEN_H
#include <Pieces.h>
#include <vector>
class Queen: public Pieces
{
    public:
        Queen(int);
        vector<Square> getMoves(Square cells[][8], int x, int y);
        static Texture blackQueen;
        static Texture whiteQueen;
    protected:

    private:
};

#endif // QUEEN_H
