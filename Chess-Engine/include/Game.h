#ifndef GAME_H
#define GAME_H
#include <Board.h>
#include <Pieces.h>
#include <Player.h>

class Game
{
    public:
        Game();
    private:
        Player player1;
        Player player2;
        Board board;
        bool gameStatus;
        bool whiteTurn;

};

#endif // GAME_H
