#include "Board.h"
#include "map"
#include "string"
#include <bitset>
#include <iostream>
#include <stdint.h>

// generate all the legal moves for the current board state
// if the current board state is a normal, return 0
// if the current board state is a checkmate (White win), return 1
// if the current board state is a checkmate (Black win), return 2
// if the current board state is a stalemate, return 3
// if the current board state is a draw, return 4

// 1. generate all the pseudo-legal moves (bitshift without regards to rules) (include castling only)

// 2. filter out the illegal moves (condition from, are all illegal)

// 2.1. if after the move our king is in check

// 2.2. if the piece warp around the board, (e.g. A file pawn moves to H file pawn)

// 2.3.  piece specific rules
// 2.3.1 pawn promotion, if the pawn reaches the 8th rank, it most promote to a queen, rook, bishop, or knight
// 2.3.2 pawn double move, only a pawn at the 2nd rank can move two squares forward
// 2.3.3 en passant, only if the en-passant square is set, that pawn can move diagonally to the en-passant square2.43

// 2.3.4 castling, 4 conditions must be met:
// 2.3.4.1 the king and the rook have not moved
// 2.3.4.2 the squares between the king and the rook are empty
// 2.3.4.3 the king is not in check
// 2.3.4.4 the king does not pass through or finish on a square that is attacked by an enemy piece

// 2.5. except for knights, if a piece is blocking the path of the move

using namespace std;

uint8_t Board::generateLegalMoves(Board *possibleLegalBoards) {


    // save the legal moves
}
