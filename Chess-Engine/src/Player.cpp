#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

Player::Player(int color){
    Color_of_Player = color;
}
// this funtion takes input the move from the player, in the form of string,
// first two letters contain the initial position of piece, while other two 
// contain the final position of a piece.
void Player::getMove(){
    cout << "Enter your Move: ";
    cin >> move;
}