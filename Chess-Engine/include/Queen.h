#ifndef QUEEN_H
#define QUEEN_H


class Queen: public Pieces
{
    public:
        vector<Square> getMoves(Square cells[][8], int x, int y);
    protected:

    private:
};

#endif // QUEEN_H
