#ifndef KING_H
#define KING_H


class King: public Pieces
{
    public:
        King();
        void isStaleMate();
        void isCheck();
        void isCheckmate();
    protected:

    private:
};

#endif // KING_H
