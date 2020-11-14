#ifndef KNIGHT_H
#define KNIGHT_H
#include <Square.h>
#include <Pieces.h>
#include <vector>
class Knight: public Pieces
{
    public:
        Knight(int);
        vector<Square> getMoves(Square cells[][8], int x, int y);
        static Texture whiteKnight;
        static Texture blackKnight;
    protected:

    private:
};

#endif // KNIGHT_H
