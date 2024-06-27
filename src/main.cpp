// main driver for the program

#include <iostream>

#include "Board/Board.h"
#include "Uci/Uci.h"

// int main() {
//     Board board;
//     Uci uci;

//     uci.loop();

//     return 0;
// }

// perft driver code
// ref: https://www.chessprogramming.org/Perft#:~:text=Perft%20is%20mostly%20for%20debugging,functions%20work%20correctly%20or%20not.

int main(){
    Board board;

    board.initFenBoard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq h3 0 1");

    board.printBoard();

    return 0;

}