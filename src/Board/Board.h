// .h file for Board class

#ifndef BOARD_H

#define BOARD_H

#include <stdint.h>

class Board {
    public:
        Board();
        ~Board();

    private:
        // bitboard notation
        // each 64 bit integer represents a piece type
        // and it's location
        // 0th index is a1, 1st index is b1, and so on
        // 64th index is h8

        // for example by default the white pawns bitboard (in binary) would be:
        /*  a b c d e f g h
          8 0 0 0 0 0 0 0 0
          7 0 0 0 0 0 0 0 0
          6 0 0 0 0 0 0 0 0
          5 0 0 0 0 0 0 0 0
          4 0 0 0 0 0 0 0 0
          3 0 0 0 0 0 0 0 0
          2 1 1 1 1 1 1 1 1
          1 0 0 0 0 0 0 0 0
        */
        // therefore the value would be 0b0000000011111111...0

        uint64_t whitePawns;
        uint64_t whiteKnights;
        uint64_t whiteBishops;
        uint64_t whiteRooks;
        uint64_t whiteQueens;
        uint64_t whiteKing;

        uint64_t blackPawns;
        uint64_t blackKnights;
        uint64_t blackBishops;
        uint64_t blackRooks;
        uint64_t blackQueens;
        uint64_t blackKing;

        // game state (castling rights, en passant square, 50 move counter, side to move)
        uint8_t castlingRights;
        uint8_t enPassantSquare;
        uint8_t fiftyMoveCounter;
        uint8_t sideToMove;

};

#endif