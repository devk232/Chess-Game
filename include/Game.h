#ifndef GAME_H
#define GAME_H
#include <Pieces.h>
#include <Player.h>
#include <SFML/Graphics.hpp>
using namespace sf;

class Game{
    public: 
        Game(Color c1, Color c2);
        void Start();
        void DrawBoard(Color c1, Color c2);
        Square cells[8][8];
    private:
        Player player1;
        Player player2;
        bool gameStatus;
        bool whiteTurn;
};

#endif // GAME_H
