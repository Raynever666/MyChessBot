#include "Board.h"
#include "map"
#include "string"
#include <bitset>
#include <iostream>
#include <stdint.h>

using namespace std;
void Board::initDefaultBoard() {
    // initialize the board with the default starting position
    // and reset all game state variables

    // default fen string
    string defaultFen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    // initialize the board with the default fen string
    initFenBoard(defaultFen);
}