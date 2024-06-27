#include "Board.h"
#include "map"
#include "string"
#include <bitset>
#include <iostream>
#include <stdint.h>
#include "chessLookUp.hpp"

// generate all the legal moves for the current board state (max 218 legal moves)
// if the current board state is a normal, return 0
// if the current board state is a checkmate (White win), return 1
// if the current board state is a checkmate (Black win), return 2
// if the current board state is a draw, return 3

// 1. generate all the pseudo-legal moves (bitshift without regards to rules) (include castling only)

// 2. filter out the illegal moves (condition from, are all legal here)

// 2.1 If the target square is an enemy or empty square

// 

using namespace std;
namespace lookup = Chess_Lookup::Lookup_Pext;

uint8_t Board::generateLegalMoves(Board *possibleLegalBoards) {

    // split legal move generator into 2 color, white and black
    // no if branch needed
    switch (whiteToMove) {
        case true:
            return generateWhiteLegalMoves(possibleLegalBoards);
            break;
        case false:
            return generateBlackLegalMoves(possibleLegalBoards);
            break;
    }
}

// ref: https://github.com/official-stockfish/Stockfish/blob/master/src/position.cpp#L485
uint8_t Board::generateWhiteLegalMoves(Board *possibleLegalBoards){

    // 1. generate all the pseudo-legal moves (bitshift without regards to rules) (include castling only)
    Board* pseudoLegalBoards = new Board[218];
    uint64_t KnightTest = lookup::Knight(whiteKnights);

    return 0;
}

uint8_t Board::generateBlackLegalMoves(Board *possibleLegalBoards){
    return 0;
}
