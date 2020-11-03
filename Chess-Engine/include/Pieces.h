#ifndef PIECES_H
#define PIECES_H


class Pieces
{
    public:
        Pieces();
        virtual bool isMoveValid(int, int, int,int);
    protected:

    private:
        bool IsAlive;        // true if there piece is alive
        int color;           // 0 if piece is white else 1
};

#endif // PIECES_H
