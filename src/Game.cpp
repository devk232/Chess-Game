#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Pieces.h"
#include "Square.h"

Game::Game(sf::Color c1, sf::Color c2){
    font.loadFromFile("Textures/arial.ttf");
    infoRestart.setFillColor(sf::Color::White);
    infoRestart.setOutlineThickness(-5.f);
    infoRestart.setOutlineColor(sf::Color::Black);
    infoRestart.setPosition(sf::Vector2f(800.f,0.f));
    infoRestart.setSize(sf::Vector2f(256.f, 50.f));
    textRestart.setFont(font);
    textRestart.setString("RESTART");
    textRestart.setCharacterSize(24);
    textRestart.setStyle(sf::Text::Bold);
    textRestart.setFillColor(sf::Color::Blue);
    textRestart.setPosition(infoRestart.getPosition().x + 75.f, infoRestart.getPosition().y + 10.f);
    turn.setFont(font);
    turn.setCharacterSize(24);
    turn.setStyle(sf::Text::Bold);
    turn.setFillColor(sf::Color::White);
    turn.setPosition(850.f, 70.f);
    situation.setFont(font);
    situation.setCharacterSize(24);
    situation.setStyle(sf::Text::Bold);
    situation.setFillColor(sf::Color::White);
    situation.setPosition(850.f, 110.f);
    w_king = new King(1);
    w_queen = new Queen(1);
    b_king = new King(0);
    b_queen = new Queen(0);
    for(int i = 0; i < 8; i++){
        b_pawn[i] = new Pawn(0);
        w_pawn[i] = new Pawn(1);
    }
    for(int i = 0; i < 2; i++){
        w_bishop[i] = new Bishop(1);
        w_rook[i] = new Rook(1);
        w_knight[i] = new Knight(1);
        b_bishop[i] = new Bishop(0);
        b_rook[i] = new Rook(0);
        b_knight[i] = new Knight(0);
    }
    Start(c1, c2);
}

void Game::Start(sf::Color c1, sf::Color c2){
    cout << "hi" << endl;
    gameStatus = true, whiteTurn = 1, selected = false;
    selected_piece = NULL;
     for(int i = 0; i < 8;i++){
        b_pawn[i]->x = i;
        b_pawn[i]->piece.setPosition(b_pawn[i]->x*100.f + 50.f, b_pawn[i]->y*100.f + 50.f);
        b_pawn[i]->piece.setOrigin(sf::Vector2f(b_pawn[i]->piece.getTexture()->getSize().x/2 , b_pawn[i]->piece.getTexture()->getSize().y/2));
        b_pawn[i]->piece.setScale(sf::Vector2f(0.375f,0.375f));
        w_pawn[i]->x = i;
        w_pawn[i]->piece.setPosition(w_pawn[i]->x*100.f + 50.f, w_pawn[i]->y*100.f + 50.f);
        w_pawn[i]->piece.setOrigin(sf::Vector2f(w_pawn[i]->piece.getTexture()->getSize().x/2 , w_pawn[i]->piece.getTexture()->getSize().y/2));
        w_pawn[i]->piece.setScale(sf::Vector2f(0.375f,0.375f));
    }
    b_bishop[0]->x = 2; b_bishop[1]->x = 5;
    b_rook[0]->x = 0; b_rook[1]->x = 7;
    b_knight[0]->x = 1; b_knight[1]->x = 6;
    w_bishop[0]->x = 2; w_bishop[1]->x = 5;
    w_rook[0]->x = 0; w_rook[1]->x = 7;
    w_knight[0]->x = 1; w_knight[1]->x = 6;
    for(int i = 0; i < 2; i++){
        b_bishop[i]->piece.setPosition(100.0f*b_bishop[i]->x + 50.f, 100.0f*b_bishop[i]->y+ 50.f);
        b_knight[i]->piece.setPosition(100.0f*b_knight[i]->x + 50.f, 100.0f*b_knight[i]->y+ 50.f);
        b_rook[i]->piece.setPosition(100.0f*b_rook[i]->x + 50.f, 100.0f*b_rook[i]->y + 50.f);
        b_bishop[i]->piece.setOrigin(100.0f*b_bishop[i]->x, 100.0f*b_bishop[i]->y);
        b_knight[i]->piece.setOrigin(100.0f*b_knight[i]->x, 100.0f*b_knight[i]->y);
        b_rook[i]->piece.setOrigin(100.0f*b_rook[i]->x, 100.0f*b_rook[i]->y);
        b_bishop[i]->piece.setOrigin(sf::Vector2f(b_bishop[i]->piece.getTexture()->getSize().x/2, b_bishop[i]->piece.getTexture()->getSize().y/2));
        b_bishop[i]->piece.setScale(sf::Vector2f(0.375f,0.375f));
        b_rook[i]->piece.setOrigin(sf::Vector2f(b_rook[i]->piece.getTexture()->getSize().x/2 , b_rook[i]->piece.getTexture()->getSize().y/2));
        b_rook[i]->piece.setScale(sf::Vector2f(0.375f,0.375f));
        b_knight[i]->piece.setOrigin(sf::Vector2f(b_knight[i]->piece.getTexture()->getSize().x/2 , b_knight[i]->piece.getTexture()->getSize().y/2));
        b_knight[i]->piece.setScale(sf::Vector2f(0.375f,0.375f));
        w_bishop[i]->piece.setPosition(100.0f*w_bishop[i]->x + 50.f, 100.0f*w_bishop[i]->y + 50.f);
        w_knight[i]->piece.setPosition(100.0f*w_knight[i]->x + 50.f, 100.0f*w_knight[i]->y + 50.f);
        w_rook[i]->piece.setPosition(100.0f*w_rook[i]->x + 50.f, 100.0f*w_rook[i]->y + 50.f);
        w_bishop[i]->piece.setOrigin(100.0f*w_bishop[i]->x, 100.0f*w_bishop[i]->y);
        w_knight[i]->piece.setOrigin(100.0f*w_knight[i]->x, 100.0f*w_knight[i]->y);
        w_rook[i]->piece.setOrigin(100.0f*w_rook[i]->x, 100.0f*w_rook[i]->y);
        w_bishop[i]->piece.setOrigin(sf::Vector2f(w_bishop[i]->piece.getTexture()->getSize().x/2 , w_bishop[i]->piece.getTexture()->getSize().y/2));
        w_bishop[i]->piece.setScale(sf::Vector2f(0.375f,0.375f));
        w_rook[i]->piece.setOrigin(sf::Vector2f(w_rook[i]->piece.getTexture()->getSize().x/2 , w_rook[i]->piece.getTexture()->getSize().y/2));
        w_rook[i]->piece.setScale(sf::Vector2f(0.375f,0.375f));
        w_knight[i]->piece.setOrigin(sf::Vector2f(w_knight[i]->piece.getTexture()->getSize().x/2 , w_knight[i]->piece.getTexture()->getSize().y/2));
        w_knight[i]->piece.setScale(sf::Vector2f(0.375f,0.375f));
    }
   for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cells[i][j].square.setPosition(sf::Vector2f(j*100.0f, i*100.0f));
            cells[i][j].square.setSize(sf::Vector2f(100.f, 100.f)); 
            cells[i][j].square.setFillColor((i + j)%2 ? c2 : c1);
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 8; j++){
            cells[7 - i][j].occupied_color = 1; 
            cells[i][j].occupied_color = -1;
        }
    }
    // loop to set up pawns on board
    for(int j = 0; j < 8; j++){
        cells[1][j].occupied_value = -3;
        cells[6][j].occupied_value = -3;
    }
    cells[0][0].occupied_value = 1;cells[7][7].occupied_value = 1;cells[7][0].occupied_value = 1;cells[0][7].occupied_value = 1; // setting up rook
    cells[0][1].occupied_value = -1;cells[7][6].occupied_value = -1;cells[0][6].occupied_value = -1;cells[7][1].occupied_value = -1; // setting up knight
    cells[0][2].occupied_value = -2;cells[7][5].occupied_value = -2;cells[0][5].occupied_value = -2;cells[7][2].occupied_value = -2; // setting up bishop
    cells[7][3].occupied_value = 2; cells[0][3].occupied_value = 2;                                                            // setting up queen
    cells[7][4].occupied_value = 3; cells[0][4].occupied_value = 3;            // setting up king 
}

void Game::SetRightSideofWindow(){
    string print = "Turn: ";
    print += (whiteTurn == 0) ? "Black" : "White";
    turn.setString(print);
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            target.draw(cells[i][j].square);
        }
    }
    //target.clear(sf::Color::Black);
    target.draw(infoRestart);
    target.draw(textRestart);
    target.draw(turn);
    target.draw(situation);
    
    if(selected_piece != NULL){
        for(int i=0; i< moves.size();i++){
            target.draw(moves[i].square);
        }
    }
    target.draw(w_king->piece);target.draw(b_king->piece);
    target.draw(w_queen->piece);target.draw(b_queen->piece);    
    for(int i = 0; i < 8; i++){
        target.draw(w_pawn[i]->piece);
        target.draw(b_pawn[i]->piece);
    }
    for(int i = 0; i < 2; i++){
        target.draw(w_bishop[i]->piece);target.draw(b_bishop[i]->piece);
        target.draw(w_rook[i]->piece);target.draw(b_rook[i]->piece);
        target.draw(w_knight[i]->piece);target.draw(b_knight[i]->piece);
    }
}

void Game::DrawPossibleMoves(){
    if(selected_piece == NULL)
        return;
    moves.clear();
    moves = selected_piece->getMoves(cells, selected_piece->x, selected_piece->y);
    for(int i=0; i< moves.size();i++){
        moves[i].square.setPosition(sf::Vector2f((moves[i].x)*100.f , (moves[i].y)*100.f));
        moves[i].square.setSize(sf::Vector2f(64.f, 64.f));
        moves[i].square.setFillColor(sf::Color(0x66b4cc50));
    }

    sf::RectangleShape tmp;
    tmp.setPosition(sf::Vector2f((selected_piece->x)*100.f , (selected_piece->y)*100.f));
    tmp.setSize(sf::Vector2f(64.f, 64.f));
    tmp.setFillColor(sf::Color(0x00000000));
    tmp.setOutlineColor(sf::Color::Red);
    tmp.setOutlineThickness(-3.f);
}

bool Game::SelectPiece(Square Cells[][8], int x, int y){
    if(Cells[x][y].occupied_color == 0){
        selected_piece = NULL;
        return false;
    }
    if(Cells[x][y].occupied_color == 1 && whiteTurn == 0 || Cells[x][y].occupied_color == -1 && whiteTurn == 1){
        selected_piece = NULL;
        return false;
    }
    if(Cells[x][y].occupied_color == 1){
        if(Cells[x][y].occupied_color == 3)
            selected_piece = w_king;
        else if(Cells[x][y].occupied_color == 2)
            selected_piece = w_queen;
        else if(Cells[x][y].occupied_color == 1){
            if(w_rook[0]->x == x && w_rook[0]->y == y)
                selected_piece = w_rook[0];
            else
                selected_piece = w_rook[1];    
        }
        else if(Cells[x][y].occupied_color == -2){
            if(w_bishop[0]->x == x && w_bishop[0]->y == y)
                selected_piece = w_bishop[0];
            else
                selected_piece = w_bishop[1];    
        }
        else if(Cells[x][y].occupied_color == -1){
            if(w_knight[0]->x == x && w_knight[0]->y == y)
                selected_piece = w_knight[0];
            else
                selected_piece = w_knight[1];    
        }else{
            for(int i = 0; i < 8; i++){
                if(w_pawn[i]->x == x && w_pawn[i]->y == y){
                    selected_piece = w_pawn[i];
                    break;
                }
            }
        }
    }else{
        if(Cells[x][y].occupied_color == 3)
            selected_piece = b_king;
        else if(Cells[x][y].occupied_color == 2)
            selected_piece = b_queen;
        else if(Cells[x][y].occupied_color == 1){
            if(b_rook[0]->x == x && b_rook[0]->y == y)
                selected_piece = b_rook[0];
            else
                selected_piece = b_rook[1];    
        }
        else if(Cells[x][y].occupied_color == -2){
            if(b_bishop[0]->x == x && b_bishop[0]->y == y)
                selected_piece = b_bishop[0];
            else
                selected_piece = b_bishop[1];    
        }
        else if(Cells[x][y].occupied_color == -1){
            if(b_knight[0]->x == x && b_knight[0]->y == y)
                selected_piece = b_knight[0];
            else
                selected_piece = b_knight[1];    
        }else{
            for(int i = 0; i < 8; i++){
                if(b_pawn[i]->x == x && b_pawn[i]->y == y){
                    selected_piece = b_pawn[i];
                    break;
                }
            }
        }
    }
    DrawPossibleMoves();
    return true;
}

void Game::moveSelected(Square Cells[][8], int x, int y){
    if(selected_piece == NULL)
        return;
    
} 


