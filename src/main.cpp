// main driver for the program

#include <iostream>

#include "Board/Board.h"
#include "Uci/Uci.h"

int main() {
    Board board;
    Uci uci;

    uci.loop();

    return 0;
}