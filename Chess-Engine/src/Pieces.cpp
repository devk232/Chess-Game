#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Pieces.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
using namespace std;

Pieces::Pieces(bool color){
    isWhite = color;
}
