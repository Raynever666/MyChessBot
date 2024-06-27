#include "Board.h"
#include "map"
#include "string"
#include <bitset>
#include <iostream>
#include <stdint.h>

using namespace std;
void Board::resetBoard() {
    // set everything to 0
    whitePawns = 0;
    whiteKnights = 0;
    whiteBishops = 0;
    whiteRooks = 0;
    whiteQueens = 0;
    whiteKing = 0;

    blackPawns = 0;
    blackKnights = 0;
    blackBishops = 0;
    blackRooks = 0;
    blackQueens = 0;
    blackKing = 0;

    whiteToMove = false;

    whiteCastleKingSide = false;
    whiteCastleQueenSide = false;

    blackCastleKingSide = false;
    blackCastleQueenSide = false;

    enPassantSquare = 0;
    halfMoveClock = 0;
    fullMoveNumber = 0;
}