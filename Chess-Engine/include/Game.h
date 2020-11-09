#ifndef GAME_H
#define GAME_H
#include <Pieces.h>
#include <Player.h>

class Game:public Player
{
    public:
        Game();
    private:
        Player player1;
        Player player2;
        Square cells[8][8];
        bool gameStatus;
        bool whiteTurn;
};

#endif // GAME_H
