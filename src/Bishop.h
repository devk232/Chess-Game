#ifndef BISHOP_H
#define BISHOP_H
#include "Pieces.h"
#include <vector>

class Bishop: public Pieces
{
    public:
        Bishop(int color);
        vector<Square> getMoves(Square cells[][8], int x, int y);
        sf::Texture blackBishop;
        sf::Texture whiteBishop;
    protected:

    private:
};

#endif // BISHOP_H