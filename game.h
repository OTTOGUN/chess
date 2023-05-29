

#include<stdio.h>

#ifndef GAME_H
#define CIRCLE_H

#define ROW 10
#define COL 10

void InitBoard(char board[ROW][COL],int row,int col);

void DisplayBoard(char board[ROW][COL],int row,int col);

void PlayerMove(char board[ROW][COL],int row,int col);

void ComputerMove(char board[ROW][COL],int row,int col);

char Is_Win(char board[ROW][COL],int row,int col);

int Location(int x,int y);

#endif
