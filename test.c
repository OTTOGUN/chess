#include "game.h"

//玩家标志:o
//电脑标志:x

void menu()
{
    printf("**************************************\n");
    printf("**************1. 开始游戏***************\n");
    printf("**************0. 退出游戏***************\n");
    printf("**************************************\n");
}

void game()
{
    //数组-存放棋盘上的棋子信息
    char board[COL][ROW] = {0};
    //初始化棋盘
    InitBoard(board,ROW,COL);
    //打印棋盘
    DisplayBoard(board,ROW,COL);
    printf("\n");
    //玩家移动
loop:
    PlayerMove(board,ROW,COL);
    DisplayBoard(board,ROW,COL);
    printf("\n");
    //判定玩家是否输赢
    char flag = Is_Win(board,ROW,COL);
    if(flag == 'o')
    {
        printf("玩家赢\n");
        goto end;
    }
    //电脑移动
    ComputerMove(board,ROW,COL);
    DisplayBoard(board,ROW,COL);
    printf("\n");
    //判断电脑是否输赢
    flag = Is_Win(board,ROW,COL);
    if(flag == 'x')
    {
        printf("电脑赢\n");
    }else if(flag == 'P'){
        printf("平局！\n");
    }else if(flag == 'C')
    {
        goto loop;
    }
    end:;
}

void test()
{
    int input = 0;
    do {
            menu();
            printf("请选择>>>\n");
            scanf("%d",&input);
            switch(input)
            {
                case 1:
                    printf("三字棋\n");
                    game();
                    break;
                case 0:
                    printf("退出游戏\n");
                    break;
                default:
                    printf("输入错误，重新选择\n");
                    break;
            }
    }while(input);
}

int main()
{
    test();
    return 0;
}