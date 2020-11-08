#ifndef BISHOP_H
#define BISHOP_H


class Bishop: public Pieces
{
    public:
        vector<Square> getMoves(Square cells[][8], int x, int y);
    protected:

    private:
};

#endif // BISHOP_H
