#ifndef TEMP_H
# define TEMP_H

#endif


#include <iostream>
#include <vector>
#include <ncurses.h>
#include "temp.h"



int player_turn = 0;

void drawChessboard(const std::vector<std::vector<char>>& chessboard, int rScale, int cScale) 
{


    
    for(int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(maskboard[i][j] != ' ')
            {
                attron(COLOR_PAIR(COLOR_GREEN));
                mvprintw(i*rScale, j*cScale, "%c ", maskboard[i][j]);
              
                attroff(COLOR_PAIR(COLOR_GREEN));
            }
            else
            {

                attron(COLOR_PAIR(COLOR_BLUE));
                mvprintw(i*rScale, j*cScale, "%c ", chessboard[i][j]);
                attroff(COLOR_PAIR(COLOR_BLUE));
             
            }
        }
    }


    refresh();
}

void clearMask()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            
                maskboard[i][j] = ' ';
            
        }
    }
}


int checkGame(std::vector<std::vector<char>>& chessboard)
{
    int ret = 2;
    int uKing = 0;
    int lKing = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
           
            if(chessboard[i][j] == PLAYER2_KING)
            {
                
               uKing = 1;
            }

            if(chessboard[i][j] == PLAYER1_KING)
            {
               
                lKing = 1;
            }
        }
    }

    if(!uKing)
    {
        ret = 0;
    }
    else if(!lKing)
    {
        ret = 1;
    }
    else
    {
        ret = 2;
    }
     

    return ret;

}

void handleInput(std::vector<std::vector<char>>& chessboard, char piece, int r, int c, int rs, int cs) 
{
       
    if (piece == PLAYER1_PAWN) 
    {
        long unsigned int forwardm = r + 1;
        
        if ((forwardm < chessboard[r].size()) && (chessboard[forwardm][c] == ' ')) 
        {
            maskboard[forwardm][c] = '@';
        }
        if(forwardm < chessboard[r].size())
        {
            if(c - 1 > -1 && chessboard[forwardm][c -1] != ' ' && !std::isupper(chessboard[forwardm][c -1]))
            {
                
                maskboard[forwardm][c - 1] = 'x';
               
               
            }
            if(c + 1 < 8 && chessboard[forwardm][c + 1] != ' ' && !std::isupper(chessboard[forwardm][c + 1]))
            {
               
                maskboard[forwardm][c + 1] = 'x';
                
                
            }
        }
        clear();
        
        mvprintw(10, 50, "Waiting.....");
        drawChessboard(chessboard, rs, cs);

        // Wait for the next mouse event
        MEVENT m;
        if (getch() == KEY_MOUSE && getmouse(&m) == OK) 
        {
            int mouseRow = m.y / rs;
            int mouseCol = (m.x+1) / cs;

            if (maskboard[mouseRow][mouseCol] == '@' || maskboard[mouseRow][mouseCol] == 'x') 
            {
                chessboard[r][c] = ' ';
                //Adds removed pieces to array
                chessboard[mouseRow][mouseCol] = PLAYER1_PAWN;
                player_turn = 1;
            }
        }

        
       
    }
    else if(piece == PLAYER1_ROOK)
    {
         
        std::vector<std::pair<int, int>> moves;

        
        for (int i = r - 1; i >= 0; i--) 
        { // up
            if (chessboard[i][c] == ' ') 
            {
                moves.emplace_back(i, c);
            } 
            else if (islower(chessboard[i][c])) 
            {
                moves.emplace_back(i, c);
                break;
            } 
            else 
            {
                break;
            }
        }

        for (int i = r + 1; i < 8; i++) 
        { // down
            if (chessboard[i][c] == ' ') 
            {
                moves.emplace_back(i, c);
            } 
            else if (islower(chessboard[i][c])) 
            {
                moves.emplace_back(i, c);
                break;
            } 
            else 
            {
                break;
            }
        }

        for (int j = c - 1; j >= 0; j--) 
        { // left
            if (chessboard[r][j] == ' ') 
            {
                moves.emplace_back(r, j);
            } 
            else if (islower(chessboard[r][j])) 
            {
                moves.emplace_back(r, j);
                break;
            } 
            else 
            {
                break;
            }
        }

        for (int j = c + 1; j < 8; j++) 
        { // right
            if (chessboard[r][j] == ' ') 
            {
                moves.emplace_back(r, j);
            } 
            else if (islower(chessboard[r][j])) 
            {
                moves.emplace_back(r, j);
                break;
            } 
            else 
            {
                break;
            }
        }

        
        for (const auto& move : moves) 
        {
            if (chessboard[move.first][move.second] == ' ') 
            {
                maskboard[move.first][move.second] = '@';
            } 
            else if (islower(chessboard[move.first][move.second])) 
            {
                maskboard[move.first][move.second] = 'x';
            }
        }

        
        clear();
        mvprintw(10, 50, "Waiting.....");
        drawChessboard(chessboard, rs, cs);

        
        MEVENT m;
        if (getch() == KEY_MOUSE && getmouse(&m) == OK) {
            int mouseRow = m.y / rs;
            int mouseCol = (m.x+1) / cs;

            if (maskboard[mouseRow][mouseCol] == '@' || maskboard[mouseRow][mouseCol] == 'x') {
                chessboard[r][c] = ' ';
             
                chessboard[mouseRow][mouseCol] = PLAYER1_ROOK;
                player_turn = 1;
            }
        }
        
    }else if(piece == PLAYER1_BISHOP){
        std::vector<std::pair<int, int>> moves;
    
        // up-left
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == ' ') {
            moves.emplace_back(i, j);
        } else if (islower(chessboard[i][j])) {
            moves.emplace_back(i, j);
            break;
        } else {
            break;
        }
        }

        // up-right
        for (int i = r - 1, j = c + 1; i >= 0 && j < 8; i--, j++) {
            if (chessboard[i][j] == ' ') {
                moves.emplace_back(i, j);
            } else if (islower(chessboard[i][j])) {
                moves.emplace_back(i, j);
                break;
            } else {
                break;
            }
        }

        // down-left
        for (int i = r + 1, j = c - 1; i < 8 && j >= 0; i++, j--) {
            if (chessboard[i][j] == ' ') {
                moves.emplace_back(i, j);
            } else if (islower(chessboard[i][j])) {
                moves.emplace_back(i, j);
                break;
            } else {
                break;
            }
        }

        // down-right
        for (int i = r + 1, j = c + 1; i < 8 && j < 8; i++, j++) {
            if (chessboard[i][j] == ' ') {
                moves.emplace_back(i, j);
            } else if (islower(chessboard[i][j])) {
                moves.emplace_back(i, j);
                break;
            } else {
                break;
            }
        }

        // Mark all valid moves on the maskboard
        for (const auto& move : moves) {
            if (chessboard[move.first][move.second] == ' ') {
                maskboard[move.first][move.second] = '@';
            } else if (islower(chessboard[move.first][move.second])) {
                maskboard[move.first][move.second] = 'x';
            }
        }

        clear();
        mvprintw(10, 50, "Waiting.....");
        drawChessboard(chessboard, rs, cs);

        // Wait for the next mouse event
        MEVENT m;
        if (getch() == KEY_MOUSE && getmouse(&m) == OK) {
            int mouseRow = m.y / rs;
            int mouseCol = (m.x+1) / cs;

            if (maskboard[mouseRow][mouseCol] == '@' || maskboard[mouseRow][mouseCol] == 'x') {
                chessboard[r][c] = ' ';
                //Adds removed pieces to array
                chessboard[mouseRow][mouseCol] = PLAYER1_BISHOP;
                player_turn = 1;
            }
        }
    }else if (piece == PLAYER1_QUEEN) {
    // Moving upwards
    for (int i = r - 1; i >= 0; i--) {
        if (chessboard[i][c] == ' ') {
            maskboard[i][c] = '@';
        } else if (islower(chessboard[i][c])) {
            maskboard[i][c] = 'x';
            break;
        } else {
            break;
        }
    }
    
    // Moving downwards
    for (int i = r + 1; i < 8; i++) {
        if (chessboard[i][c] == ' ') {
            maskboard[i][c] = '@';
        } else if (islower(chessboard[i][c])) {
            maskboard[i][c] = 'x';
            break;
        } else {
            break;
        }
    }
    
    // Moving leftwards
    for (int j = c - 1; j >= 0; j--) {
        if (chessboard[r][j] == ' ') {
            maskboard[r][j] = '@';
        } else if (islower(chessboard[r][j])) {
            maskboard[r][j] = 'x';
            break;
        } else {
            break;
        }
    }
    
    // Moving rightwards
    for (int j = c + 1; j < 8; j++) {
        if (chessboard[r][j] == ' ') {
            maskboard[r][j] = '@';
        } else if (islower(chessboard[r][j])) {
            maskboard[r][j] = 'x';
            break;
        } else {
            break;
        }
    }
    
    // Moving diagonally upwards and leftwards
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == ' ') {
            maskboard[i][j] = '@';
        } else if (islower(chessboard[i][j])) {
            maskboard[i][j] = 'x';
            break;
        } else {
            break;
        }
    }
    
    // Moving diagonally upwards and rightwards
    for (int i = r - 1, j = c + 1; i >= 0 && j < 8; i--, j++) {
        if (chessboard[i][j] == ' ') {
            maskboard[i][j] = '@';
        } else if (islower(chessboard[i][j])) {
            maskboard[i][j] = 'x';
            break;
        } else {
            break;
        }
    }
    
    // Moving diagonally downwards and leftwards
    for (int i = r + 1, j = c - 1; i < 8 && j >= 0; i++, j--) {
        if (chessboard[i][j] == ' ') {
            maskboard[i][j] = '@';
        } else if (islower(chessboard[i][j])) {
            maskboard[i][j] = 'x';
            break;
        } else {
            break;
        }
    }
    
    // Moving diagonally downwards and rightwards
    for (int i = r + 1, j = c + 1; i < 8 && j < 8; i++, j++) {
        if (chessboard[i][j] == ' ') {
            maskboard[i][j] = '\0';
        // If the current square has an enemy piece, mark it with 'x' and break the loop
        } else if (islower(chessboard[i][j])) {
            maskboard[i][j] = 'x';
            break;
        // If the current square has a friendly piece, break the loop
        } else {
            break;
        }
    }

        for (int i = r + 1, j = c + 1; i < 8 && j < 8; i++, j++) {
            if (chessboard[i][j] == ' ') {
                maskboard[i][j] = '@';
            } else if (islower(chessboard[i][j])) {
                maskboard[i][j] = 'x';
                break;
            } else {
                break;
            }
        }

        clear();
        mvprintw(10, 50, "Waiting.....");
        drawChessboard(chessboard, rs, cs);

        // Wait for the next mouse event
        MEVENT m;
        if (getch() == KEY_MOUSE && getmouse(&m) == OK) {
            int mouseRow = m.y / rs;
            int mouseCol = (m.x+1) / cs;

            if (maskboard[mouseRow][mouseCol] == '@' || maskboard[mouseRow][mouseCol] == 'x') {
                chessboard[r][c] = ' ';
                //Adds removed pieces to array
                chessboard[mouseRow][mouseCol] = PLAYER1_QUEEN;
                player_turn = 1;
            }
        }
    
    }else if (piece == PLAYER1_KNIGHT) {
        std::vector<std::pair<int, int>> moves = {
            {r - 2, c - 1}, {r - 2, c + 1},
            {r - 1, c - 2}, {r - 1, c + 2},
            {r + 1, c - 2}, {r + 1, c + 2},
            {r + 2, c - 1}, {r + 2, c + 1}
        };

        for (const auto& move : moves) {
            int mr = move.first, mc = move.second;
            if (mr >= 0 && mr < 8 && mc >= 0 && mc < 8) {
                if (chessboard[mr][mc] == ' '){
                  
                    maskboard[mr][mc] = '@';
                }else if(islower(chessboard[mr][mc]) ){
                    maskboard[mr][mc] = 'x';
                }
            }
        }

        clear();
        mvprintw(10, 50, "Waiting.....");
        drawChessboard(chessboard, rs, cs);

        // Wait for the next mouse event
        MEVENT m;
        if (getch() == KEY_MOUSE && getmouse(&m) == OK) {
            int mouseRow = m.y / rs;
            int mouseCol = (m.x+1) / cs;

            if (maskboard[mouseRow][mouseCol] == '@' || maskboard[mouseRow][mouseCol] == 'x' ) {
                chessboard[r][c] = ' ';
                //Adds removed pieces to array
                chessboard[mouseRow][mouseCol] = PLAYER1_KNIGHT;
                player_turn = 1;
            }
        }
    }else if (piece == PLAYER1_KING) {
        std::vector<std::pair<int, int>> moves;

        // up
        if (r - 1 >= 0) {
            moves.emplace_back(r - 1, c);
        }
        // down
        if (r + 1 < 8) {
            moves.emplace_back(r + 1, c);
        }
        // left
        if (c - 1 >= 0) {
            moves.emplace_back(r, c - 1);
        }
        // right
        if (c + 1 < 8) {
            moves.emplace_back(r, c + 1);
        }
        // up-left
        if (r - 1 >= 0 && c - 1 >= 0) {
            moves.emplace_back(r - 1, c - 1);
        }
        // up-right
        if (r - 1 >= 0 && c + 1 < 8) {
            moves.emplace_back(r - 1, c + 1);
        }
        // down-left
        if (r + 1 < 8 && c - 1 >= 0) {
            moves.emplace_back(r + 1, c - 1);
        }
        // down-right
        if (r + 1 < 8 && c + 1 < 8) {
            moves.emplace_back(r + 1, c + 1);
        }

        for (const auto& move : moves) {
            if (chessboard[move.first][move.second] == ' ') {
                maskboard[move.first][move.second] = '@';
            } else if (islower(chessboard[move.first][move.second])) {
                maskboard[move.first][move.second] = 'x';
            }
        }

        clear();
        mvprintw(10, 50, "Waiting.....");
        drawChessboard(chessboard, rs, cs);

        // Wait for the next mouse event
        MEVENT m;
        if (getch() == KEY_MOUSE && getmouse(&m) == OK) {
            int mouseRow = m.y / rs;
            int mouseCol = (m.x+1) / cs;

            if (maskboard[mouseRow][mouseCol] == '@' || maskboard[mouseRow][mouseCol] == 'x') {
                chessboard[r][c] = ' ';
                //Adds removed pieces to array
                chessboard[mouseRow][mouseCol] = PLAYER1_KING;
                player_turn = 1;
            }
        }
    }


    
    
    clearMask();
  
}


void handleInput2(std::vector<std::vector<char>>& chessboard, char piece, int r, int c, int rs, int cs) {
    mvprintw(15, 50, "PLAYER 2 TURN");
    if (piece == PLAYER2_PAWN) {
         int forwardm = r - 1;
        
        if ((forwardm > -1) && (chessboard[forwardm][c] == ' ')) {
            maskboard[forwardm][c] = '@';
        }
        if(forwardm > -1){
            if(c - 1 > -1 && chessboard[forwardm][c -1] != ' ' && !std::islower(chessboard[forwardm][c -1])){
                
                maskboard[forwardm][c - 1] = 'x';
               
               
            }
            if(c + 1 < 8 && chessboard[forwardm][c + 1] != ' ' && !std::islower(chessboard[forwardm][c + 1])){
               
                maskboard[forwardm][c + 1] = 'x';
                
                
            }
        }
        clear();
        mvprintw(10, 50, "Waiting.....");
        drawChessboard(chessboard, rs, cs);

        // Wait for the next mouse event
        MEVENT m;
        if (getch() == KEY_MOUSE && getmouse(&m) == OK) {
            int mouseRow = m.y / rs;
            int mouseCol = (m.x+1) / cs;

            if (maskboard[mouseRow][mouseCol] == '@' || maskboard[mouseRow][mouseCol] == 'x') {
                chessboard[r][c] = ' ';
                //Adds removed pieces to array
                chessboard[mouseRow][mouseCol] = PLAYER2_PAWN;
                player_turn = 0;
            }
        }

        
       
    }else if(piece == PLAYER2_ROOK){
         
        std::vector<std::pair<int, int>> moves;

        
        for (int i = r - 1; i >= 0; i--) { // up
            if (chessboard[i][c] == ' ') {
                moves.emplace_back(i, c);
            } else if (isupper(chessboard[i][c])) {
                moves.emplace_back(i, c);
                break;
            } else {
                break;
            }
        }

        for (int i = r + 1; i < 8; i++) { // down
            if (chessboard[i][c] == ' ') {
                moves.emplace_back(i, c);
            } else if (isupper(chessboard[i][c])) {
                moves.emplace_back(i, c);
                break;
            } else {
                break;
            }
        }

        for (int j = c - 1; j >= 0; j--) { // left
            if (chessboard[r][j] == ' ') {
                moves.emplace_back(r, j);
            } else if (isupper(chessboard[r][j])) {
                moves.emplace_back(r, j);
                break;
            } else {
                break;
            }
        }

        for (int j = c + 1; j < 8; j++) { // right
            if (chessboard[r][j] == ' ') {
                moves.emplace_back(r, j);
            } else if (isupper(chessboard[r][j])) {
                moves.emplace_back(r, j);
                break;
            } else {
                break;
            }
        }

        
        for (const auto& move : moves) {
            if (chessboard[move.first][move.second] == ' ') {
                maskboard[move.first][move.second] = '@';
            } else if (isupper(chessboard[move.first][move.second])) {
                maskboard[move.first][move.second] = 'x';
            }
        }

        
        clear();
        mvprintw(10, 50, "Waiting.....");
        drawChessboard(chessboard, rs, cs);

        
        MEVENT m;
        if (getch() == KEY_MOUSE && getmouse(&m) == OK) {
            int mouseRow = m.y / rs;
            int mouseCol = (m.x+1) / cs;

            if (maskboard[mouseRow][mouseCol] == '@' || maskboard[mouseRow][mouseCol] == 'x') {
                chessboard[r][c] = ' ';
             
                chessboard[mouseRow][mouseCol] = PLAYER2_ROOK;
                player_turn = 0;
            }
        }
        
    }else if(piece == PLAYER2_BISHOP){
        std::vector<std::pair<int, int>> moves;
    
        // up-left
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == ' ') {
            moves.emplace_back(i, j);
        } else if (isupper(chessboard[i][j])) {
            moves.emplace_back(i, j);
            break;
        } else {
            break;
        }
        }

        // up-right
        for (int i = r - 1, j = c + 1; i >= 0 && j < 8; i--, j++) {
            if (chessboard[i][j] == ' ') {
                moves.emplace_back(i, j);
            } else if (isupper(chessboard[i][j])) {
                moves.emplace_back(i, j);
                break;
            } else {
                break;
            }
        }

        // down-left
        for (int i = r + 1, j = c - 1; i < 8 && j >= 0; i++, j--) {
            if (chessboard[i][j] == ' ') {
                moves.emplace_back(i, j);
            } else if (isupper(chessboard[i][j])) {
                moves.emplace_back(i, j);
                break;
            } else {
                break;
            }
        }

        // down-right
        for (int i = r + 1, j = c + 1; i < 8 && j < 8; i++, j++) {
            if (chessboard[i][j] == ' ') {
                moves.emplace_back(i, j);
            } else if (isupper(chessboard[i][j])) {
                moves.emplace_back(i, j);
                break;
            } else {
                break;
            }
        }

        // Mark all valid moves on the maskboard
        for (const auto& move : moves) {
            if (chessboard[move.first][move.second] == ' ') {
                maskboard[move.first][move.second] = '@';
            } else if (isupper(chessboard[move.first][move.second])) {
                maskboard[move.first][move.second] = 'x';
            }
        }

        clear();
        mvprintw(10, 50, "Waiting.....");
        drawChessboard(chessboard, rs, cs);

        // Wait for the next mouse event
        MEVENT m;
        if (getch() == KEY_MOUSE && getmouse(&m) == OK) {
            int mouseRow = m.y / rs;
            int mouseCol = (m.x+1) / cs;

            if (maskboard[mouseRow][mouseCol] == '@' || maskboard[mouseRow][mouseCol] == 'x') {
                chessboard[r][c] = ' ';
                //Adds removed pieces to array
                chessboard[mouseRow][mouseCol] = PLAYER2_BISHOP;
                player_turn = 0;
            }
        }
    }else if (piece == PLAYER2_QUEEN) {
    // Moving upwards
    for (int i = r - 1; i >= 0; i--) {
        if (chessboard[i][c] == ' ') {
            maskboard[i][c] = '@';
        } else if (isupper(chessboard[i][c])) {
            maskboard[i][c] = 'x';
            break;
        } else {
            break;
        }
    }
    
    // Moving downwards
    for (int i = r + 1; i < 8; i++) {
        if (chessboard[i][c] == ' ') {
            maskboard[i][c] = '@';
        } else if (isupper(chessboard[i][c])) {
            maskboard[i][c] = 'x';
            break;
        } else {
            break;
        }
    }
    
    // Moving leftwards
    for (int j = c - 1; j >= 0; j--) {
        if (chessboard[r][j] == ' ') {
            maskboard[r][j] = '@';
        } else if (isupper(chessboard[r][j])) {
            maskboard[r][j] = 'x';
            break;
        } else {
            break;
        }
    }
    
    // Moving rightwards
    for (int j = c + 1; j < 8; j++) {
        if (chessboard[r][j] == ' ') {
            maskboard[r][j] = '@';
        } else if (isupper(chessboard[r][j])) {
            maskboard[r][j] = 'x';
            break;
        } else {
            break;
        }
    }
    
    // Moving diagonally upwards and leftwards
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == ' ') {
            maskboard[i][j] = '@';
        } else if (isupper(chessboard[i][j])) {
            maskboard[i][j] = 'x';
            break;
        } else {
            break;
        }
    }
    
    // Moving diagonally upwards and rightwards
    for (int i = r - 1, j = c + 1; i >= 0 && j < 8; i--, j++) {
        if (chessboard[i][j] == ' ') {
            maskboard[i][j] = '@';
        } else if (isupper(chessboard[i][j])) {
            maskboard[i][j] = 'x';
            break;
        } else {
            break;
        }
    }
    
    // Moving diagonally downwards and leftwards
    for (int i = r + 1, j = c - 1; i < 8 && j >= 0; i++, j--) {
        if (chessboard[i][j] == ' ') {
            maskboard[i][j] = '@';
        } else if (isupper(chessboard[i][j])) {
            maskboard[i][j] = 'x';
            break;
        } else {
            break;
        }
    }
    
    // Moving diagonally downwards and rightwards
    for (int i = r + 1, j = c + 1; i < 8 && j < 8; i++, j++) {
        if (chessboard[i][j] == ' ') {
            maskboard[i][j] = '\0';
        // If the current square has an enemy piece, mark it with 'x' and break the loop
        } else if (isupper(chessboard[i][j])) {
            maskboard[i][j] = 'x';
            break;
        // If the current square has a friendly piece, break the loop
        } else {
            break;
        }
    }

        for (int i = r + 1, j = c + 1; i < 8 && j < 8; i++, j++) {
            if (chessboard[i][j] == ' ') {
                maskboard[i][j] = '@';
            } else if (isupper(chessboard[i][j])) {
                maskboard[i][j] = 'x';
                break;
            } else {
                break;
            }
        }

        clear();
        mvprintw(10, 50, "Waiting.....");
        drawChessboard(chessboard, rs, cs);

        // Wait for the next mouse event
        MEVENT m;
        if (getch() == KEY_MOUSE && getmouse(&m) == OK) {
            int mouseRow = m.y / rs;
            int mouseCol = (m.x+1) / cs;

            if (maskboard[mouseRow][mouseCol] == '@' || maskboard[mouseRow][mouseCol] == 'x') {
                chessboard[r][c] = ' ';
                //Adds removed pieces to array
                chessboard[mouseRow][mouseCol] = PLAYER2_QUEEN;
                player_turn = 0;
            }
        }
    
    }else if (piece == PLAYER2_KNIGHT) {
        std::vector<std::pair<int, int>> moves = {
            {r - 2, c - 1}, {r - 2, c + 1},
            {r - 1, c - 2}, {r - 1, c + 2},
            {r + 1, c - 2}, {r + 1, c + 2},
            {r + 2, c - 1}, {r + 2, c + 1}
        };

        for (const auto& move : moves) {
            int mr = move.first, mc = move.second;
            if (mr >= 0 && mr < 8 && mc >= 0 && mc < 8) {
                if (chessboard[mr][mc] == ' '){
                  
                    maskboard[mr][mc] = '@';
                }else if(isupper(chessboard[mr][mc]) ){
                    maskboard[mr][mc] = 'x';
                }
            }
        }

        clear();
        mvprintw(10, 50, "Waiting.....");
        drawChessboard(chessboard, rs, cs);

        // Wait for the next mouse event
        MEVENT m;
        if (getch() == KEY_MOUSE && getmouse(&m) == OK) {
            int mouseRow = m.y / rs;
            int mouseCol = (m.x+1) / cs;

            if (maskboard[mouseRow][mouseCol] == '@' || maskboard[mouseRow][mouseCol] == 'x' ) {
                chessboard[r][c] = ' ';
                //Adds removed pieces to array
                chessboard[mouseRow][mouseCol] = PLAYER2_KNIGHT;
                player_turn = 0;
            }
        }
    }else if (piece == PLAYER2_KING) {
        std::vector<std::pair<int, int>> moves;

        // up
        if (r - 1 >= 0) {
            moves.emplace_back(r - 1, c);
        }
        // down
        if (r + 1 < 8) {
            moves.emplace_back(r + 1, c);
        }
        // left
        if (c - 1 >= 0) {
            moves.emplace_back(r, c - 1);
        }
        // right
        if (c + 1 < 8) {
            moves.emplace_back(r, c + 1);
        }
        // up-left
        if (r - 1 >= 0 && c - 1 >= 0) {
            moves.emplace_back(r - 1, c - 1);
        }
        // up-right
        if (r - 1 >= 0 && c + 1 < 8) {
            moves.emplace_back(r - 1, c + 1);
        }
        // down-left
        if (r + 1 < 8 && c - 1 >= 0) {
            moves.emplace_back(r + 1, c - 1);
        }
        // down-right
        if (r + 1 < 8 && c + 1 < 8) {
            moves.emplace_back(r + 1, c + 1);
        }

        for (const auto& move : moves) {
            if (chessboard[move.first][move.second] == ' ') {
                maskboard[move.first][move.second] = '@';
            } else if (isupper(chessboard[move.first][move.second])) {
                maskboard[move.first][move.second] = 'x';
            }
        }

        clear();
        mvprintw(10, 50, "Waiting.....");
        drawChessboard(chessboard, rs, cs);

        // Wait for the next mouse event
        MEVENT m;
        if (getch() == KEY_MOUSE && getmouse(&m) == OK) {
            int mouseRow = m.y / rs;
            int mouseCol = (m.x+1) / cs;

            if (maskboard[mouseRow][mouseCol] == '@' || maskboard[mouseRow][mouseCol] == 'x') {
                chessboard[r][c] = ' ';
                //Adds removed pieces to array
                chessboard[mouseRow][mouseCol] = PLAYER2_KING;
                player_turn = 0;
            }
        }
    }


    
    
    clearMask();
  
}


int main() {
    // Initialize the chessboard
    int rs = 2; 
    int cs = 3;
     int gameOver = 0;


    // Initializing the ncurses
    initscr();
    cbreak();
    noecho();
    start_color();
    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);

    keypad(stdscr, TRUE);
    mousemask(BUTTON1_PRESSED          , NULL);

    mouseinterval(0);
    mousemask(BUTTON1_PRESSED          , NULL);

    keypad(stdscr, TRUE);
    mousemask(BUTTON1_PRESSED          , NULL);


    clear();


    // Game loop
    while (true) {
        // Wait for a mouse click
        if(!gameOver){
            if(player_turn == 0){ 
            mvprintw(5, 50, "PLAYER 1 TURN");
        }else {
            mvprintw(15, 50, "PLAYER 2 TURN");
            }
             
        drawChessboard(chessboard,rs,cs);
        MEVENT event;
        if (getch() == KEY_MOUSE && getmouse(&event) == OK) {
            // Calculates the chessboard position based on mouse click coordinates
            long unsigned int row = event.y/2;
            long unsigned int col = event.x/3;
        
            if (row >= 0 && row < chessboard.size() && col >= 0 && col < chessboard[row].size()) {
          
                 
                     if(player_turn == 0){ 
                        handleInput(chessboard,chessboard[row][(event.x + 1)/cs],row,(event.x + 1)/cs,rs,cs);
                        
                       
                    }else {
                        handleInput2(chessboard,chessboard[row][(event.x + 1)/cs],row,(event.x + 1)/cs,rs,cs);
                     }
                        int g = checkGame(chessboard);
                        if(g == 0){
                            gameOver = 1;
                            clear();
                            refresh();
                            mvprintw(10,20,"PLAYER 1 WON!!!");
                            
                        }else if(g == 1){

                             gameOver = 1;
                            clear();
                            refresh();
                            mvprintw(10,20,"PLAYER 2 WON!!!");
                        }
            }
        }
        }else{
            getch();
            break;
        }
    }


    endwin();

    return 0;
}


