#ifndef PIECES_H
#define PIECES_H


class Pieces{
    public:
        Pieces(bool color);
    private:
        int x, y;      // to see the position of a piece
        bool isAlive;
        bool isWhite;
};

#endif // PIECES_H
