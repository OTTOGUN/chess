#include "game.h"

//��ұ�־:o
//���Ա�־:x

void menu()
{
    printf("**************************************\n");
    printf("**************1. ��ʼ��Ϸ***************\n");
    printf("**************0. �˳���Ϸ***************\n");
    printf("**************************************\n");
}

void game()
{
    //����-��������ϵ�������Ϣ
    char board[COL][ROW] = {0};
    //��ʼ������
    InitBoard(board,ROW,COL);
    //��ӡ����
    DisplayBoard(board,ROW,COL);
    printf("\n");
    //����ƶ�
loop:
    PlayerMove(board,ROW,COL);
    DisplayBoard(board,ROW,COL);
    printf("\n");
    //�ж�����Ƿ���Ӯ
    char flag = Is_Win(board,ROW,COL);
    if(flag == 'o')
    {
        printf("���Ӯ\n");
        goto end;
    }
    //�����ƶ�
    ComputerMove(board,ROW,COL);
    DisplayBoard(board,ROW,COL);
    printf("\n");
    //�жϵ����Ƿ���Ӯ
    flag = Is_Win(board,ROW,COL);
    if(flag == 'x')
    {
        printf("����Ӯ\n");
    }else if(flag == 'P'){
        printf("ƽ�֣�\n");
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
            printf("��ѡ��>>>\n");
            scanf("%d",&input);
            switch(input)
            {
                case 1:
                    printf("������\n");
                    game();
                    break;
                case 0:
                    printf("�˳���Ϸ\n");
                    break;
                default:
                    printf("�����������ѡ��\n");
                    break;
            }
    }while(input);
}

int main()
{
    test();
    return 0;
}