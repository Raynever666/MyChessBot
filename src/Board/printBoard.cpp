#include "Board.h"
#include "map"
#include "string"
#include <bitset>
#include <iostream>
#include <stdint.h>

using namespace std;

// by copilot
void Board::printBoard() {
    // print the board to the console
    // in a human readable format

    // loop through the 64 squares
    // and print the piece on the square
    // if there is no piece, print a "."
    // start from a8 (file 0, rank 7) and go to h1 (file 7, rank 0)
    int a = 1;
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            int fileT = 7 - file;
            uint64_t square = 1ULL << (rank * 8 + fileT);

            // sorry for this nested if else
            // co-pilot wrote this, too lazy to change
            if (whitePawns & square) {
                cout << "P ";
            } else if (whiteKnights & square) {
                cout << "N ";
            } else if (whiteBishops & square) {
                cout << "B ";
            } else if (whiteRooks & square) {
                cout << "R ";
            } else if (whiteQueens & square) {
                cout << "Q ";
            } else if (whiteKing & square) {
                cout << "K ";
            } else if (blackPawns & square) {
                cout << "p ";
            } else if (blackKnights & square) {
                cout << "n ";
            } else if (blackBishops & square) {
                cout << "b ";
            } else if (blackRooks & square) {
                cout << "r ";
            } else if (blackQueens & square) {
                cout << "q ";
            } else if (blackKing & square) {
                cout << "k ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}