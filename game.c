//
// Created by 39221 on 2023/5/27.
//

#include "game.h"
#include <stdlib.h>

int *a1;
int *a2;

int Location(int x,int y)
{
    *a1 = x - 1;
    *a2 = y - 1;
}

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

//������ʽ
/*    |   |
   ---|---|---
      |   |
   ---|---|---
      |   |   */
void DisplayBoard(char board[ROW][COL],int row,int col)
{
    //ÿһ��
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
        printf("��������������(��ʽ X:  Y:  )\n");
        scanf("%d%d",&x,&y);
        if(x >= 1 && x < row + 1 && y >= 1 && y < col + 1)
        {
            if(board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = 'o';
                Location(x,y);
                break;
            }else
            {
                printf("�������ѱ�ռ��\n");
            }
        }else
        {
            printf("����Խ�磬������������ȷ����\n");
        }
    }
}

void ComputerMove(char board[ROW][COL],int row,int col)
{
    while(1)
    {
        int x = rand() % ROW;
        int y = rand() % COL;

        if(board[x][y] == ' ')
        {
            board[x][y] = 'x';
            break;
        }
    }
}

char Is_Win(char board[ROW][COL],int row,int col)
{
    //��һ��  ������  a1 = x
    if(*a1 > 0)
    {
        if(board[*a1][*a2 - 1] == board[*a1][*a2] == board[*a1][*a2 + 1] && board[*a1][*a2] != ' ')
        {
            return board[*a1][*a2];
        }
    }else if(*a1 == 0)
    {
        if(board[*a1][*a2 + 1] == board[*a1][*a2] == board[*a1][*a2 + 2] && board[*a1][*a2] != ' ')
        {
            return board[*a1][*a2];
        }
    }else if(*a1 = row - 1)
    {
        if(board[*a1][*a2 - 1] == board[*a1][*a2] == board[*a1][*a2 - 2] && board[*a1][*a2] != ' ')
        {
            return board[*a1][*a2];
        }
    }

    //��һ��  ������  a2 = y
    if(*a2 > 0)
    {
        if(board[*a1 - 1][0] == board[*a1][1] == board[*a1 + 1][2] && board[*a1][*a2] != ' ')
        {
            return board[*a1][*a2];
        }
    }else if(*a2 == 0)
    {
        if(board[*a1 + 1][*a2] == board[*a1][*a2] == board[*a1 + 2][*a2] && board[*a1][*a2] != ' ')
        {
            return board[*a1][*a2];
        }
    }else if(*a2 = col - 1)
    {
        if(board[*a1 - 1][*a2] == board[*a1][*a2] == board[*a1 - 2][*a2] && board[*a1][*a2] != ' ')
        {
            return board[*a1][*a2];
        }
    }

    //�Խ���һ��
    if()
}