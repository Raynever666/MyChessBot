// .h file for Board class

#ifndef BOARD_H

#define BOARD_H

#include <stdint.h>
#include "string"

class Board {
    public:
        Board();
        ~Board();

        // on initFenBoard.cpp
        void initFenBoard(std::string fen);

        // on generateLegalMoves.cpp
        uint8_t generateLegalMoves(Board* possibleLegalBoards);

        // on printBoard.cpp
        void printBoard();

        // initDefaultBoard.cpp
        void initDefaultBoard();

        // on Board.cpp
        void makeMove();
        void unmakeMove();

        void printFen();

        void resetBoard();


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
        // therefore the value would be 0b0000 0000 1111 1111...0

        uint64_t whitePawns = 0;
        uint64_t whiteKnights = 0;
        uint64_t whiteBishops = 0;
        uint64_t whiteRooks = 0;
        uint64_t whiteQueens = 0;
        uint64_t whiteKing = 0;

        uint64_t blackPawns = 0;
        uint64_t blackKnights = 0;
        uint64_t blackBishops = 0;
        uint64_t blackRooks = 0;
        uint64_t blackQueens = 0;
        uint64_t blackKing = 0;

        // game state (castling rights, en passant square, 50 move counter, side to move)
        bool whiteToMove = false;

        bool whiteCastleKingSide = false;
        bool whiteCastleQueenSide = false;

        bool blackCastleKingSide = false;
        bool blackCastleQueenSide = false;

        uint64_t enPassantSquare = 0;

        // The number of half moves since the last capture or pawn advance, 
        // used for the fifty-move rule.
        int halfMoveClock = 0;

        // The number of the full moves. 
        // It starts at 1 and is incremented after Black's move.
        int fullMoveNumber = 0; 

};

#endif