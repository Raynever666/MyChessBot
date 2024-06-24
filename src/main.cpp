// main driver for the program

#include <iostream>

#include "Board.h"
#include "Uci.h"

int main() {
    Board board;
    Uci uci;

    uci.loop();

    return 0;
}