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

// ref: https://www.youtube.com/watch?v=U4ogK0MIzqk&t=365s
// at 2:35
void Board::initFenBoard(string fen) {

    // initialize the board with a piecePlacement string
    // load the piecePlacement string into the respective bitboards
    // and reset all game state variables according to piecePlacement 

    Board::resetBoard();

    // load the piece type seen in piecePlacement into a dictionary
    std::map<char, int> pieceTypeFromSymbol = {
        // white pieces
        {'P', 0},
        {'N', 1},
        {'B', 2},
        {'R', 3},
        {'Q', 4},
        {'K', 5},

        // black pieces
        {'p', 6},
        {'n', 7},
        {'b', 8},
        {'r', 9},
        {'q', 10},
        {'k', 11}
    };

    string original = fen;

    // split the first " " into the piecePlacement string
    // cut until the first " " to get the piecePlacement string
    string piecePlacement = fen.substr(0, fen.find(" "));
    fen = fen.substr(fen.find(" ") + 1);

    // split the second " " into the active color string (either w or b, representing white or black)
    string sideToMoveStr = fen.substr(0, fen.find(" "));
    fen = fen.substr(fen.find(" ") + 1);

    // split the third " " into the castling rights string
    string castlingRightsStr = fen.substr(0, fen.find(" "));
    fen = fen.substr(fen.find(" ") + 1);

    // split the fourth " " into the en passant square string
    string enPassantSquareStr = fen.substr(0, fen.find(" "));
    fen = fen.substr(fen.find(" ") + 1);

    // split the fifth " " into the half move clock string
    string halfMoveClockStr = fen.substr(0, fen.find(" "));
    fen = fen.substr(fen.find(" ") + 1);

    // split the sixth " " into the full move number string
    string fullMoveNumber = fen.substr(0, fen.find(" "));

    // loop through the piecePlacement string until a " "
    // piecePlacement notation start at top rank (a8) and goes to bottom rank (h1)
    int file = 0, rank = 7;
    for (int i = 0; i < piecePlacement.length(); i++) {
        // if the character is a number, skip that many squares
        if (isdigit(piecePlacement[i])) {
            file += piecePlacement[i] - '0' - 1;
        } else if (piecePlacement[i] == '/') {
            // if the character is a "/", move to the next rank
            file = 0;
            rank--;
        } else {
            // if the character is a piece, set the bitboard
            // for that piece to the correct square

            // find what symbol it is from map
            int pieceType = pieceTypeFromSymbol[piecePlacement[i]];

            // transform the file number
            // when it is 7, it should be 0 for bit manipulation
            int fileT = 7 - file;

            // some bit manipulation to get the correct square
            // on the 64 bit integer
            uint64_t square = 1ULL << (rank * 8 + fileT);

            switch (pieceType) {
                case 0:
                    whitePawns |= square;
                    break;
                case 1:
                    whiteKnights |= square;
                    break;
                case 2:
                    whiteBishops |= square;
                    break;
                case 3:
                    whiteRooks |= square;
                    break;
                case 4:
                    whiteQueens |= square;
                    break;
                case 5:
                    whiteKing |= square;
                    break;
                case 6:
                    blackPawns |= square;
                    break;
                case 7:
                    blackKnights |= square;
                    break;
                case 8:
                    blackBishops |= square;
                    break;
                case 9:
                    blackRooks |= square;
                    break;
                case 10:
                    blackQueens |= square;
                    break;
                case 11:
                    blackKing |= square;
                    break;
            }
            file++;
        }

    }
    
    // convert the activeColor string to bitboard representation (an integer)
    if (sideToMoveStr == "w") {
        sideToMove = 0;
    } else {
        sideToMove = 1;
    }

    // convert the castlingRights string to bitboard representation (an integer)
    // in total there are 16 (2^4) possible castling rights
    // KQkq, KQq, etc

    // we can use a 8 bit integer (use 4 bit) to represent the castling rights
    // e.g. 0000 1111 would represent all castling rights (KQkq)
    // e.g. 0000 1101 would represent KQq
    // e.g. 0000 1001 would represent Kq

    // "-" represents no castling rights, thus the integer would be 0000 0000
    for (int i = 0; i < castlingRightsStr.length(); i++) {
        switch (castlingRightsStr[i]) {
            case 'K':
                castlingRights |= 0b0001;
                break;
            case 'Q':
                castlingRights |= 0b0010;
                break;
            case 'k':
                castlingRights |= 0b0100;
                break;
            case 'q':
                castlingRights |= 0b1000;
                break;
        }
    }

    // convert the enPassantSquare string to bitboard representation (an integer)
    // the en passant in fen represent the square where the pawn can en-passant
    // for example after move 1. e4, the en passant square would be e3

    // since only 2 rank can have en passant, we can use a 64 bit integer to represent the en passant square
    // the just like the piece bitboards, the 64 bit integer would have a 1 at the square where the en passant can occur
    // and 0 everywhere else

    // if there is no en passant square, all bit would be 0
    for (int i = 0; i < enPassantSquareStr.length(); i++) {
        if (enPassantSquareStr[i] == '-') {
            enPassantSquare = 0;
        } else {
            // some bit manipulation to get the correct square
            // on the 64 bit integer
            file = 7 - (enPassantSquareStr[i] - 'a');
            rank = enPassantSquareStr[i + 1] - '1';
            enPassantSquare = 1ULL << (rank * 8 + file);
        }
    }

    // convert the halfMoveClock string to bitboard representation (an integer)
    // just a number no bit manipulation needed :)
    halfMoveClock = stoi(halfMoveClockStr);

    // convert the fullMoveNumber string to bitboard representation (an integer)
    // just a number no bit manipulation needed :)
    fullMoveNumber = stoi(fullMoveNumber);


    
}

void Board::initDefaultBoard() {
    // initialize the board with the default starting position
    // and reset all game state variables

    // default fen string
    string defaultFen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    // initialize the board with the default fen string
    initFenBoard(defaultFen);

}

void Board::makeMove() {
    // make a move on the board
    // update the board state variables

}

void Board::unmakeMove() {
    // unmake a move on the board
    // update the board state variables

}

void Board::generateLegalMoves() {
    // generate all the legal moves for the current board state
    // and store them in a list

}

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

void Board::printFen() {
    // print the board state in FEN notation
    // to the console
    // TODO
}

void Board::resetBoard() {
    // set everything to 0
    whitePawns = 0;
    whiteKnights = 0;
    whiteBishops = 0;
    whiteRooks = 0;
    whiteQueens = 0;
    whiteKing = 0;

    blackPawns = 0;
    blackKnights = 0;
    blackBishops = 0;
    blackRooks = 0;
    blackQueens = 0;
    blackKing = 0;

    sideToMove = 0;
    castlingRights = 0;
    enPassantSquare = 0;
    halfMoveClock = 0;
    fullMoveNumber = 0;
    
}
