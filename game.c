//
// Created by 39221 on 2023/5/27.
//

#include "game.h"
#include <stdlib.h>
#include <malloc.h>

int a1 = 0;
int a2 = 0;

void InitBoard(char board[ROW][COL],int row,int col)
{
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < col;j++)
        {
            board[i][j] = ' ';
        }
    }
}

//棋盘样式
/*    |   |
   ---|---|---
      |   |
   ---|---|---
      |   |   */
void DisplayBoard(char board[ROW][COL],int row,int col)
{
    //每一行
    for(int i = 0;i < row;i++)
    {
        if(i < row - 1) {
            for (int j = 0; j < col; j++) {
                if (j < col - 1) {
                    printf(" %c |", board[i][j]);
                } else {
                    printf(" %c \n", board[i][j]);
                }
            }
            for (int j = 0; j < col; j++) {
                if (j < col - 1) {
                    printf("---|");
                } else {
                    printf("---\n");
                }
            }
        }else
            {
                for(int j = 0;j < col;j++)
                {
                    if(j < col - 1)
                    {
                        printf(" %c |",board[i][j]);
                    }else
                    {
                        printf(" %c \n",board[i][j]);
                    }
                }
            }
    }
}

void PlayerMove(char board[ROW][COL],int row,int col){
    int x,y;
    while(1)
    {
        printf("请输入落子坐标(格式 X:  Y:  )\n");
        scanf("%d%d",&x,&y);
        if(x >= 1 && x < row + 1 && y >= 1 && y < col + 1)
        {
            if(board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = 'o';
                a1 = x - 1,a2 = y - 1;
                break;
            }else
            {
                printf("该坐标已被占用\n");
            }
        }else
        {
            printf("坐标越界，请重新输入正确坐标\n");
        }
    }
}

void ComputerMove(char board[ROW][COL],int row,int col)
{
    while(1)
    {
        int x = rand() % ROW;
        int y = rand() % COL;

        a1 = x;
        a2 = y;

        if(board[x][y] == ' ')
        {
            board[x][y] = 'x';
            break;
        }
    }
}

char Is_Win(char board[ROW][COL],int row,int col)
{
    //列一致  》》》  a1 = x
        if(board[a1][a2 - 1] == board[a1][a2] && board[a1][a2 + 1] == board[a1][a2] && board[a1][a2] != ' ')
        {
            return board[a1][a2];
        }else if(board[a1][a2 - 1] == board[a1][a2] && board[a1][a2 - 2] == board[a1][a2] && board[a1][a2] != ' ')
        {
            return board[a1][a2];
        }else if(board[a1][a2 + 1] == board[a1][a2] && board[a1][a2] == board[a1][a2 + 2] && board[a1][a2] != ' ')
        {
            return board[a1][a2];
        }

    //行一致  》》》  a2 = y
        if(board[a1 - 1][a2] == board[a1][a2] && board[a1 + 1][a2] == board[a1][a2] && board[a1][a2] != ' ')
        {
            return board[a1][a2];
        }else if(board[a1 + 1][a2] == board[a1][a2] && board[a1 + 2][a2] == board[a1][a2] && board[a1][a2] != ' ')
        {
            return board[a1][a2];
        }else if(board[a1 - 1][a2] == board[a1][a2] && board[a1 - 2][a2] == board[a1][a2] && board[a1][a2] != ' ')
        {
            return board[a1][a2];
        }
    //对角线一致
    if(board[0][0] == board[1][1] && board [2][2] == board[1][1] && board[0][0] != ' ')
    {
        return board[0][0];
    }else if(board[2][0] == board[1][1] && board [0][2] == board[1][1] && board[0][2] != ' ')
    {
        return board[1][1];
    }

    //平局
    for(int i = 0; i < col;i++)
    {
        for(int j = 0;j < row;j++)
        {
            if(board[i][j] == ' ')
            {
                return 'C';
            }
        }
    }
}