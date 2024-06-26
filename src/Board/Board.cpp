// Board handler

#include "Board.h"
#include "map"
#include "string"
#include <bitset>
#include <iostream>
#include <stdint.h>

using namespace std;

Board::Board() {
    // empty constructor
}

Board::~Board() {
    // empty destructor
}

void Board::makeMove() {
    // make a move on the board
    // update the board state variables
    // TODO
}

void Board::unmakeMove() {
    // unmake a move on the board
    // update the board state variables
}

void Board::generateLegalMoves() {
    // generate all the legal moves for the current board state
    // and store them in a list
    //!! HIGH PIORITY
}

void Board::printFen() {
    // print the board state in FEN notation
    // to the console
    // TODO
}
