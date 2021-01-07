#include <iostream>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Pieces.h"
#include "Square.h"

Game::Game(sf::Color c1, sf::Color c2)
{
    font.loadFromFile("Textures/roboto.ttf");
    infoRestart.setFillColor(sf::Color::White);
    infoRestart.setOutlineThickness(-5.f);
    infoRestart.setOutlineColor(sf::Color::Black);
    infoRestart.setPosition(sf::Vector2f(850.f, 0.f));
    infoRestart.setSize(sf::Vector2f(180.f, 60.f));
    textRestart.setFont(font);
    textRestart.setString("Start Again");
    textRestart.setCharacterSize(28);
    textRestart.setFillColor(sf::Color::Blue);
    textRestart.setPosition(infoRestart.getPosition().x + 35.f, infoRestart.getPosition().y + 13.f);
    turn.setFont(font);
    turn.setCharacterSize(30);
    turn.setStyle(sf::Text::Regular);
    turn.setFillColor(sf::Color::White);
    turn.setPosition(880.f, 70.f);
    chance.setFont(font);
    chance.setCharacterSize(30);
    chance.setStyle(sf::Text::Regular);
    chance.setFillColor(sf::Color::White);
    chance.setPosition(turn.getPosition().x, turn.getPosition().y + 50.f);
    situation.setFont(font);
    situation.setCharacterSize(30);
    situation.setStyle(sf::Text::Regular);
    situation.setFillColor(sf::Color::White);
    situation.setPosition(chance.getPosition().x, chance.getPosition().y + 50.f);
    w_king = new King(1);
    whitePieces.push_back(w_king);
    w_queen = new Queen(1);
    whitePieces.push_back(w_queen);
    b_king = new King(0);
    blackPieces.push_back(b_king);
    b_queen = new Queen(0);
    blackPieces.push_back(b_queen);
    for (int i = 0; i < 8; i++)
    {
        b_pawn[i] = new Pawn(0);
        blackPieces.push_back(b_pawn[i]);
        w_pawn[i] = new Pawn(1);
        whitePieces.push_back(w_pawn[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        w_bishop[i] = new Bishop(1);
        whitePieces.push_back(w_bishop[i]);
        w_rook[i] = new Rook(1);
        whitePieces.push_back(w_rook[i]);
        w_knight[i] = new Knight(1);
        whitePieces.push_back(w_knight[i]);
        b_bishop[i] = new Bishop(0);
        blackPieces.push_back(b_bishop[i]);
        b_rook[i] = new Rook(0);
        blackPieces.push_back(b_rook[i]);
        b_knight[i] = new Knight(0);
        blackPieces.push_back(b_knight[i]);
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cells[i][j].x = i;
            cells[i][j].y = j;
        }
    }
    Start(c1, c2);
}

void Game::Start(sf::Color c1, sf::Color c2)
{
    number_of_moves = 0;
    isOver = false;
    gameStatus = true, whiteTurn = 1, selected = false;
    selected_piece = NULL;
    for (int i = 0; i < 8; i++)
    {
        b_pawn[i]->y = i;
        b_pawn[i]->piece.setPosition(b_pawn[i]->y * 100.f + 50.f, b_pawn[i]->x * 100.f + 50.f);
        b_pawn[i]->piece.setOrigin(sf::Vector2f(b_pawn[i]->piece.getTexture()->getSize().x / 2, b_pawn[i]->piece.getTexture()->getSize().y / 2));
        b_pawn[i]->piece.setScale(sf::Vector2f(0.375f, 0.375f));
        w_pawn[i]->y = i;
        w_pawn[i]->piece.setPosition(w_pawn[i]->y * 100.f + 50.f, w_pawn[i]->x * 100.f + 50.f);
        w_pawn[i]->piece.setOrigin(sf::Vector2f(w_pawn[i]->piece.getTexture()->getSize().x / 2, w_pawn[i]->piece.getTexture()->getSize().y / 2));
        w_pawn[i]->piece.setScale(sf::Vector2f(0.375f, 0.375f));
    }
    b_bishop[0]->y = 2;
    b_bishop[1]->y = 5;
    b_rook[0]->y = 0;
    b_rook[1]->y = 7;
    b_knight[0]->y = 1;
    b_knight[1]->y = 6;
    w_bishop[0]->y = 2;
    w_bishop[1]->y = 5;
    w_rook[0]->y = 0;
    w_rook[1]->y = 7;
    w_knight[0]->y = 1;
    w_knight[1]->y = 6;
    for (int i = 0; i < 2; i++)
    {
        b_bishop[i]->piece.setPosition(100.0f * b_bishop[i]->y + 50.f, 100.0f * b_bishop[i]->x + 50.f);
        b_knight[i]->piece.setPosition(100.0f * b_knight[i]->y + 50.f, 100.0f * b_knight[i]->x + 50.f);
        b_rook[i]->piece.setPosition(100.0f * b_rook[i]->y + 50.f, 100.0f * b_rook[i]->x + 50.f);
        b_bishop[i]->piece.setOrigin(100.0f * b_bishop[i]->x, 100.0f * b_bishop[i]->y);
        b_knight[i]->piece.setOrigin(100.0f * b_knight[i]->x, 100.0f * b_knight[i]->y);
        b_rook[i]->piece.setOrigin(100.0f * b_rook[i]->x, 100.0f * b_rook[i]->y);
        b_bishop[i]->piece.setOrigin(sf::Vector2f(b_bishop[i]->piece.getTexture()->getSize().x / 2, b_bishop[i]->piece.getTexture()->getSize().y / 2));
        b_bishop[i]->piece.setScale(sf::Vector2f(0.375f, 0.375f));
        b_rook[i]->piece.setOrigin(sf::Vector2f(b_rook[i]->piece.getTexture()->getSize().x / 2, b_rook[i]->piece.getTexture()->getSize().y / 2));
        b_rook[i]->piece.setScale(sf::Vector2f(0.375f, 0.375f));
        b_knight[i]->piece.setOrigin(sf::Vector2f(b_knight[i]->piece.getTexture()->getSize().x / 2, b_knight[i]->piece.getTexture()->getSize().y / 2));
        b_knight[i]->piece.setScale(sf::Vector2f(0.375f, 0.375f));
        w_bishop[i]->piece.setPosition(100.0f * w_bishop[i]->y + 50.f, 100.0f * w_bishop[i]->x + 50.f);
        w_knight[i]->piece.setPosition(100.0f * w_knight[i]->y + 50.f, 100.0f * w_knight[i]->x + 50.f);
        w_rook[i]->piece.setPosition(100.0f * w_rook[i]->y + 50.f, 100.0f * w_rook[i]->x + 50.f);
        w_bishop[i]->piece.setOrigin(100.0f * w_bishop[i]->x, 100.0f * w_bishop[i]->y);
        w_knight[i]->piece.setOrigin(100.0f * w_knight[i]->x, 100.0f * w_knight[i]->y);
        w_rook[i]->piece.setOrigin(100.0f * w_rook[i]->x, 100.0f * w_rook[i]->y);
        w_bishop[i]->piece.setOrigin(sf::Vector2f(w_bishop[i]->piece.getTexture()->getSize().x / 2, w_bishop[i]->piece.getTexture()->getSize().y / 2));
        w_bishop[i]->piece.setScale(sf::Vector2f(0.375f, 0.375f));
        w_rook[i]->piece.setOrigin(sf::Vector2f(w_rook[i]->piece.getTexture()->getSize().x / 2, w_rook[i]->piece.getTexture()->getSize().y / 2));
        w_rook[i]->piece.setScale(sf::Vector2f(0.375f, 0.375f));
        w_knight[i]->piece.setOrigin(sf::Vector2f(w_knight[i]->piece.getTexture()->getSize().x / 2, w_knight[i]->piece.getTexture()->getSize().y / 2));
        w_knight[i]->piece.setScale(sf::Vector2f(0.375f, 0.375f));
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cells[i][j].square.setPosition(sf::Vector2f(j * 100.0f, i * 100.0f));
            cells[i][j].square.setSize(sf::Vector2f(100.f, 100.f));
            cells[i][j].square.setFillColor((i + j) % 2 ? c2 : c1);
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cells[7 - i][j].occupied_color = 1;
            cells[i][j].occupied_color = -1;
        }
    }
    // loop to set up pawns on board
    for (int j = 0; j < 8; j++)
    {
        cells[1][j].occupied_value = -3;
        cells[6][j].occupied_value = -3;
    }
    cells[0][0].occupied_value = 1;
    cells[7][7].occupied_value = 1;
    cells[7][0].occupied_value = 1;
    cells[0][7].occupied_value = 1; // setting up rook
    cells[0][1].occupied_value = -1;
    cells[7][6].occupied_value = -1;
    cells[0][6].occupied_value = -1;
    cells[7][1].occupied_value = -1; // setting up knight
    cells[0][2].occupied_value = -2;
    cells[7][5].occupied_value = -2;
    cells[0][5].occupied_value = -2;
    cells[7][2].occupied_value = -2; // setting up bishop
    cells[7][3].occupied_value = 2;
    cells[0][3].occupied_value = 2; // setting up queen
    cells[7][4].occupied_value = 3;
    cells[0][4].occupied_value = 3; // setting up king
    SetRightSideofWindow();
}

void Game::SetRightSideofWindow()
{
    turn.setString("Moves: " + std::to_string(number_of_moves/2 + number_of_moves%2));
    number_of_moves++;
    if(whiteTurn == 0 && !isOver)
        chance.setString("Black's Turn");
    else if(whiteTurn == 1 && !isOver)
        chance.setString("White's Turn");   
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.clear();
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            target.draw(cells[i][j].square);
        }
    }
    target.draw(infoRestart);
    target.draw(textRestart);
    target.draw(turn);
    target.draw(situation);
    if(isOver == false)
        target.draw(chance);
    for (int i = 0; i < moves.size(); i++)
    {
        target.draw(moves[i].square);
    }

    if ((selected_piece != NULL))
    {
        for (int i = 0; i < newmoves.size(); i++)
        {
            target.draw(newmoves[i]);
        }
    }
    for (int i = 0; i < whitePieces.size(); i++)
    {
        if (whitePieces[i]->isAlive)
        {
            target.draw(whitePieces[i]->piece);
        }
        // if(!whitePieces[i]->isAlive){
        //      if(!w_king->isAlive){
        //         sleep(3);
        //         exit(0);
        //      }
        // }
    }
    for (int i = 0; i < blackPieces.size(); i++)
    {
        if (blackPieces[i]->isAlive)
        {
            target.draw(blackPieces[i]->piece);
        }
        // if(!blackPieces[i]->isAlive){
        //      if(!b_king->isAlive){
        //         sleep(3);
        //         exit(0);
        //      }
        // }
    }
}

void Game::gameOver()
{
    isOver = true;
    if (whiteTurn == 0)
        situation.setString("CHECKMATE! \n White Won!!");
    else
        situation.setString("CHECKMATE! \n Black Won!!");
}

void Game::DrawPossibleMoves()
{
    if (selected_piece == NULL)
        return;
    newmoves.clear();
    moves.clear();
    moves = selected_piece->getMoves(cells, selected_piece->x, selected_piece->y);
    for (int i = 0; i < moves.size(); i++)
    {
        sf::RectangleShape tmp;
        tmp.setPosition(sf::Vector2f((moves[i].y) * 100.f, (moves[i].x) * 100.f));
        tmp.setSize(sf::Vector2f(100.f, 100.f));
        tmp.setFillColor(sf::Color(0x66b4cc50));
        newmoves.push_back(tmp);
    }
    sf::RectangleShape tmp;
    tmp.setPosition(sf::Vector2f((selected_piece->y) * 100.f, (selected_piece->x) * 100.f));
    tmp.setSize(sf::Vector2f(100.f, 100.f));
    tmp.setFillColor(sf::Color(0x00000000));
    tmp.setOutlineColor(sf::Color::Red);
    tmp.setOutlineThickness(-3.f);
    newmoves.push_back(tmp);
}

bool Game::SelectPiece(Square Cells[][8], int x, int y)
{
    if (Cells[x][y].occupied_color == 0)
    {
        selected_piece = NULL;
        return false;
    }
    if (Cells[x][y].occupied_color == 1 && whiteTurn == 0 || Cells[x][y].occupied_color == -1 && whiteTurn == 1)
    {
        selected_piece = NULL;
        return false;
    }
    selected = true;
    if (Cells[x][y].occupied_color == 1)
    {
        if (Cells[x][y].occupied_value == 3)
            selected_piece = w_king;
        else if (Cells[x][y].occupied_value == 2)
            selected_piece = w_queen;
        else if (Cells[x][y].occupied_value == 1)
        {
            if (w_rook[0]->x == x && w_rook[0]->y == y)
                selected_piece = w_rook[0];
            else
                selected_piece = w_rook[1];
        }
        else if (Cells[x][y].occupied_value == -2)
        {
            if (w_bishop[0]->x == x && w_bishop[0]->y == y)
                selected_piece = w_bishop[0];
            else
                selected_piece = w_bishop[1];
        }
        else if (Cells[x][y].occupied_value == -1)
        {
            if (w_knight[0]->x == x && w_knight[0]->y == y)
                selected_piece = w_knight[0];
            else
                selected_piece = w_knight[1];
        }
        else if (Cells[x][y].occupied_value == -3)
        {
            for (int i = 0; i < 8; i++)
            {
                if (w_pawn[i]->x == x && w_pawn[i]->y == y)
                {
                    selected_piece = w_pawn[i];
                    break;
                }
            }
        }
    }
    else
    {
        if (Cells[x][y].occupied_value == 3)
            selected_piece = b_king;
        else if (Cells[x][y].occupied_value == 2)
            selected_piece = b_queen;
        else if (Cells[x][y].occupied_value == 1)
        {
            if (b_rook[0]->x == x && b_rook[0]->y == y)
                selected_piece = b_rook[0];
            else
                selected_piece = b_rook[1];
        }
        else if (Cells[x][y].occupied_value == -2)
        {
            if (b_bishop[0]->x == x && b_bishop[0]->y == y)
                selected_piece = b_bishop[0];
            else
                selected_piece = b_bishop[1];
        }
        else if (Cells[x][y].occupied_value == -1)
        {
            if (b_knight[0]->x == x && b_knight[0]->y == y)
                selected_piece = b_knight[0];
            else
                selected_piece = b_knight[1];
        }
        else
        {
            for (int i = 0; i < 8; i++)
            {
                if (b_pawn[i]->x == x && b_pawn[i]->y == y)
                {
                    selected_piece = b_pawn[i];
                    break;
                }
            }
        }
    }
    DrawPossibleMoves();
    return true;
}
bool Game::getSelected()
{
    return selected;
}

void Game::moveSelected(Square Cells[][8], int x, int y)
{
    if (selected_piece == NULL)
        return;
    bool valid = false;
    vector<Square> a = selected_piece->getMoves(cells, selected_piece->x, selected_piece->y);
    for (int i = 0; i < a.size(); i++)
    {
        if (x == a[i].x && y == a[i].y)
        {
            valid = true;
            break;
        }
    }
    if (valid)
    {
        selected_piece->piece.setPosition(sf::Vector2f(100.f * y + 50.f, 100.f * x + 50.f));
        int a = selected_piece->x, b = selected_piece->y;
        if (Cells[x][y].occupied_color != 0 && Cells[x][y].occupied_color != Cells[a][b].occupied_color)
        {
            if (Cells[x][y].occupied_color == 1)
            {
                for (int i = 0; i < whitePieces.size(); i++)
                {
                    if (whitePieces[i]->x == x && whitePieces[i]->y == y)
                    {
                        whitePieces[i]->isAlive = false;
                    }
                }
            }
            else
            {
                for (int i = 0; i < blackPieces.size(); i++)
                {
                    if (blackPieces[i]->x == x && blackPieces[i]->y == y)
                    {
                        blackPieces[i]->isAlive = false;
                    }
                }
            }
        }
        Cells[x][y].occupied_color = (whiteTurn == 1) ? 1 : -1;
        Cells[x][y].occupied_value = selected_piece->occupied_value;
        Cells[a][b].occupied_value = 0;
        Cells[selected_piece->x][selected_piece->y].occupied_color = 0;
        if (whiteTurn)
        {
            if (w_king->x == a && w_king->y == b)
                w_king->x = x, w_king->y = y;
            else if (w_queen->x == a && w_queen->y == b)
                w_queen->x = x, w_queen->y = y;
            else if (w_bishop[0]->x == a && w_bishop[0]->y == b)
                w_bishop[0]->x = x, w_bishop[0]->y = y;
            else if (w_bishop[1]->x == a && w_bishop[1]->y == b)
                w_bishop[1]->x = x, w_bishop[1]->y = y;
            else if (w_knight[0]->x == a && w_knight[0]->y == b)
                w_knight[0]->x = x, w_knight[0]->y = y;
            else if (w_knight[1]->x == a && w_knight[1]->y == b)
                w_knight[1]->x = x, w_knight[1]->y = y;
            else if (w_rook[0]->x == a && w_rook[0]->y == b)
                w_rook[0]->x = x, w_rook[0]->y = y;
            else if (w_rook[1]->x == a && w_rook[1]->y == b)
                w_rook[1]->x = x, w_rook[1]->y = y;
            else
            {
                for (int i = 0; i < 8; i++)
                {
                    if (w_pawn[i]->x == a && w_pawn[i]->y == b)
                    {
                        w_pawn[i]->x = x;
                        w_pawn[i]->y = y;
                        break;
                    }
                }
            }
        }
        else
        {
            if (b_king->x == a && b_king->y == b)
                b_king->x = x, b_king->y = y;
            else if (b_queen->x == a && b_queen->y == b)
                b_queen->x = x, b_queen->y = y;
            else if (b_bishop[0]->x == a && b_bishop[0]->y == b)
                b_bishop[0]->x = x, b_bishop[0]->y = y;
            else if (b_bishop[1]->x == a && b_bishop[1]->y == b)
                b_bishop[1]->x = x, b_bishop[1]->y = y;
            else if (b_knight[0]->x == a && b_knight[0]->y == b)
                b_knight[0]->x = x, b_knight[0]->y = y;
            else if (b_knight[1]->x == a && b_knight[1]->y == b)
                b_knight[1]->x = x, b_knight[1]->y = y;
            else if (b_rook[0]->x == a && b_rook[0]->y == b)
                b_rook[0]->x = x, b_rook[0]->y = y;
            else if (b_rook[1]->x == a && b_rook[1]->y == b)
                b_rook[1]->x = x, b_rook[1]->y = y;
            else
            {
                for (int i = 0; i < 8; i++)
                {
                    if (b_pawn[i]->x == a && b_pawn[i]->y == b)
                    {
                        b_pawn[i]->x = x;
                        b_pawn[i]->y = y;
                    }
                }
            }
        }
        whiteTurn = !whiteTurn;
        SetRightSideofWindow();
    }
    if (!w_king->isAlive || !b_king->isAlive)
    {
        gameOver();
    }
    selected_piece = NULL;
    selected = false;
}
