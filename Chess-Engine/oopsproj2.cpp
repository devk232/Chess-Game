#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


class ChessPiece {
    public:
    const std::string position;
    const std::string piece;
    bool is_captured;
    ChessPiece(std::string position, std::string piece, bool is_captured) :
    position(position), piece(piece), is_captured(is_captured) {};
};

class PlayerBase {
    public:
        bool is_checked = false;        
        std::vector<const ChessPiece*> pieces;
        char colour;
        void print_pieces() {
            for(auto &cp : pieces) {
                std::cout << cp->piece << " is_alive "
                    << cp->is_captured << std::endl;
            }
        }

        /* 
         * Add a ChessPiece to pieces as necessary.
         */ 
        void add_pieces(const ChessPiece*);

        /* 
         * Remove a ChessPiece to pieces as necessary.
         */ 
        void remove_pieces(const ChessPiece&);
        /*
         * Process a player's desired next move (includes checks if it is a
         * valid move and will call and erase methods if necessary
         */
        virtual ChessPiece next_move(ChessPiece cp)
        {
            return cp;
        };

};

void PlayerBase::add_pieces(const ChessPiece *cp) {
        pieces.push_back(cp);
};

void PlayerBase::remove_pieces(const ChessPiece& cp) {

        /* remove description:
         * Transforms the range [first,last) into a range with all the elements 
         * that compare equal to val removed, and returns an iterator to the new end
         * of that range.
         */
        auto it = std::remove(pieces.begin(), pieces.end(), &cp);
        pieces.erase(it , pieces.end());
};

class HumanPlayer : PlayerBase {
    /*
     * Here next_move is taken as an input
     */
    ChessPiece next_move(ChessPiece cp) { return cp; };
};

class Computer : PlayerBase {
    ChessPiece move;
    /*
     * Computer calculates an appropriate move depending on difficulty rating
     */
    ChessPiece next_move() { return move; };
};

class Player_1 : public PlayerBase {
    public:
        char colour = 'W';


};

class Player_2 : public PlayerBase {
    public:
        char colour = 'B';

};

class GameManager {
    public:
        ChessPiece process_turn(PlayerBase player) 
        {
            std::cout << "processing " << player.colour << std::endl;
            /*
             * Here the player would input a possible move for a chess piece
             */
            ChessPiece cp("foo", "bar", false);
            return cp;

        };
        bool accept_turn(ChessPiece turn)
        { 
            /* Perform checks on chesspiece returned by process_turn() above.
             * Return true if move is valid
             */
            return true; 
        };
        /*
         * Setup the game
         */
        void setup(PlayerBase&, PlayerBase&);

        void teardown(PlayerBase&, PlayerBase&);
};


void GameManager::setup(PlayerBase& p1, PlayerBase& p2) {
    /*
     * Here we prepare the chess board. For example by creating 8 pawns
     */
    for(int i = 0; i < 16; i++) {
        if(i < 8) {
            ChessPiece *p = new ChessPiece("a1", "Pawn", false);
            p1.add_pieces(p);

        }
    }
}

void GameManager::teardown(PlayerBase& p1, PlayerBase& p2) {

    //delete ChessPieces created in setup()
};

int main()
{
    Player_1 p1;
    Player_2 p2;
    GameManager game;
    game.setup(p1, p2);
    p1.print_pieces();
   // while(!p1.is_checked && !p2.is_checked) {
   //     ChessPiece move_to_make = game.process_turn(p1);
   //     game.accept_turn(move_to_make);
   //     move_to_make = game.process_turn(p1);
   //     game.accept_turn(move_to_make);
   // }
    game.teardown(p1, p2);
    return 0;
}
