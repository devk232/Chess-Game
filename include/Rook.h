#ifndef ROOK_H
#define ROOK_H
#include <Pieces.h>
#include <vector>
class Rook: public Pieces{
    public:
      Rook(int);
      vector<Square> getMoves(Square cells[][8], int x, int y);
      static Texture blackRook;
      static Texture whiteRook;
    protected:

    private:
};

#endif // ROOK_H
