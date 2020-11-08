#ifndef KNIGHT_H
#define KNIGHT_H


class Knight: public Pieces
{
    public:
        Knight();
        vector<Square> getMoves(Square cells[][8], int x, int y);
    protected:

    private:
};

#endif // KNIGHT_H
