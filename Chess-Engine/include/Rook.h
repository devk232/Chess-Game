#ifndef ROOK_H
#define ROOK_H


class Rook: public Pieces{
    public:
        Rook();
        vector<Square> getMoves(Square cells[][8], int x, int y);
    protected:

    private:
};

#endif // ROOK_H
