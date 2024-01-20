#ifndef TEMP_H
# define TEMP_H

#include <iostream>
#include <vector>
#include <ncurses.h>


#endif

std::vector<std::vector<char>> maskboard = 
{
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};


#define PLAYER1_PAWN         'P'  
#define PLAYER1_ROOK         'R'
#define PLAYER1_KNIGHT       'N'
#define PLAYER1_BISHOP       'B'
#define PLAYER1_QUEEN        'Q'
#define PLAYER1_KING         'K'

#define PLAYER2_PAWN         'p'
#define PLAYER2_ROOK         'r'
#define PLAYER2_KNIGHT       'n'
#define PLAYER2_BISHOP       'b'
#define PLAYER2_QUEEN        'q'
#define PLAYER2_KING         'k'


    std::vector<std::vector<char>> chessboard = {
        {PLAYER1_ROOK, PLAYER1_KNIGHT, PLAYER1_BISHOP, PLAYER1_QUEEN, PLAYER1_KING, PLAYER1_BISHOP, PLAYER1_KNIGHT, PLAYER1_ROOK},
        {PLAYER1_PAWN, PLAYER1_PAWN, PLAYER1_PAWN, PLAYER1_PAWN, PLAYER1_PAWN, PLAYER1_PAWN, PLAYER1_PAWN, PLAYER1_PAWN},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {PLAYER2_PAWN, PLAYER2_PAWN, PLAYER2_PAWN, PLAYER2_PAWN, PLAYER2_PAWN, PLAYER2_PAWN, PLAYER2_PAWN, PLAYER2_PAWN},
        {PLAYER2_ROOK, PLAYER2_KNIGHT, PLAYER2_BISHOP, PLAYER2_QUEEN, PLAYER2_KING, PLAYER2_BISHOP, PLAYER2_KNIGHT, PLAYER2_ROOK}
    };

