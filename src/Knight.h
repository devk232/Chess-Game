#ifndef KNIGHT_H
#define KNIGHT_H

#include <vector>
#include "Square.h"
#include "Pieces.h"
using namespace std;

class Knight : public Pieces
{
public:
    Knight(int);
    vector<Square> getMoves(Square cells[][8], int x, int y);
    sf::Texture whiteKnight;
    sf::Texture blackKnight;

protected:
private:
};

#endif // KNIGHT_H
