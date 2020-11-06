#ifndef QUEEN_H
#define QUEEN_H


class Queen: public Pieces
{
    public:
        Queen();
        bool CheckMove(int,int ,int ,int);
    protected:

    private:
};

#endif // QUEEN_H
