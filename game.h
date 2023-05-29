

#include<stdio.h>

#ifndef GAME_H
#define CIRCLE_H

#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL],int row,int col);

void DisplayBoard(char board[ROW][COL],int row,int col);

void PlayerMove(char board[ROW][COL],int row,int col);

void ComputerMove(char board[ROW][COL],int row,int col);

char Is_Win(char board[ROW][COL],int row,int col);

#endif
