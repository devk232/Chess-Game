#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Pieces.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"

class Game : public sf::Drawable
{
public:
    Game(sf::Color c1, sf::Color c2);
    void Start(sf::Color c1, sf::Color c2);
    void DrawPossibleMoves();
    bool SelectPiece(Square Cells[][8], int x, int y);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void moveSelected(Square Cells[][8], int x, int y);
    bool getSelected();
    void gameOver();
    void SetRightSideofWindow();
    Square cells[8][8];
    bool isOver;
private:
    vector<Square> moves;
    vector<sf::RectangleShape> newmoves;
    vector<Pieces *> whitePieces;
    vector<Pieces *> blackPieces;
    // white pieces
    King *w_king;
    Queen *w_queen;
    Bishop *w_bishop[2];
    Rook *w_rook[2];
    Knight *w_knight[2];
    Pawn *w_pawn[8];
    // black pieces
    King *b_king;
    Queen *b_queen;
    Bishop *b_bishop[2];
    Rook *b_rook[2];
    Knight *b_knight[2];
    Pawn *b_pawn[8];

    bool gameStatus, selected, whiteTurn;
    Pieces *selected_piece;
    sf::Font font;
    sf::RectangleShape infoRestart;
    sf::Text turn, situation, textRestart, chance;
    int number_of_moves;
};

#endif
