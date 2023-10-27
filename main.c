
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void board(void);
void single_play(void);
void multi_play(void);
int check_win(char *c);
int p1 = 0;
int p2 = 0;
char arr[3][3] = {{'1', '2', '3'},
                  {'4', '5', '6'},
                  {'7', '8', '9'}};
int main()
{
    int c = 1;
    int p = 1;
    do
    {
        board();
        printf("\n\tplease select type of play\n");
        printf("\t1 -> for single play  \n");
        printf("\t2 -> for multi play  \n");
        printf("\t0 -> to exist  \n");
        printf("\t >> ");
        scanf("%d", &p);
        while (getchar() != '\n')
            ;
        if (p == 1)
        {
            while (c)
            {
                board();
                single_play();
                printf("\n\t1 -> for continue ");
                printf("\n\t0 -> to exist\n");
                printf("\t >> ");

                scanf("%d", &c);
                if (c == 1)
                {
                    for (int i = 0; i < 9; i++)
                    {
                        *(*arr + i) = i + 49;
                    }
                }
                else if (c == 0)
                {
                    printf("\n\t Thank You \n");
                }
                else
                {
                    printf("\n\tInvalid Number\n");
                }
            }
        }
        else if (p == 2)
        {
            while (c)
            {
                board();
                multi_play();
                printf("\n\t1 -> for continue ");
                printf("\n\t0 -> to exist\n");
                printf("\t >> ");

                scanf("%d", &c);
                if (c == 1)
                {
                    for (int i = 0; i < 9; i++)
                    {
                        *(*arr + i) = i + 49;
                    }
                }
                else if (c == 0)
                {
                    printf("\n\t Thank You \n");
                }
                else
                {
                    printf("\n\tInvalid Number\n");
                }
            }
        }
        else if (p == 0)
        {
            return 0;
        }
        else
        {
            printf("Invalid Number \n");
        }

    } while (p&&c);
    

    return 0;
}

void board(void)
{

    int returned = 0;

    system("cls");
    printf("\t\t\t\t\t\t\t\t player_1 : %d      player_2 : %d \n", p1, p2);
    printf("\t\t|\t|\n");
    printf("\t    %c   |   %c   |   %c   \n", arr[0][0], arr[0][1], arr[0][2]);
    printf("\t   -----+-------+-----\n");
    printf("\t\t|\t|\n");
    printf("\t    %c   |   %c   |   %c   \n", arr[1][0], arr[1][1], arr[1][2]);
    printf("\t   -----+-------+-----\n");
    printf("\t\t|\t|\n");
    printf("\t    %c   |   %c   |   %c   \n", arr[2][0], arr[2][1], arr[2][2]);
}

void single_play(void)
{
    int player = 0;
    char op = 0;
    char win = 0;
    int returned = 0;
    int flag = 1;
    printf("\n\n");
    printf("\t Please Select player \n");
    printf("\t 1->  Player_1  \"X\" \n");
    printf("\t 1->  Player_2  \"O\" \n");
    printf("\t >> ");
    scanf("%d", &player);
    while (getchar() != '\n')
        ;
    if (player == 1)
    {
        do
        {
            board();

            do
            {

                printf("\n");
                printf("\tPlayer 1, enter your move (1-9):  ");
                scanf("%c", &op);
                while (getchar() != '\n')
                    ;
                if (*(*arr + (op - 48) - 1) == op)
                {
                    *(*arr + (op - 48) - 1) = 'X';
                    flag = 1;
                    board();
                }
                else
                {
                    board();
                    printf("\n");
                    printf("\tthis position is selected \n");
                    printf("\tTry again \n");

                    flag = 0;
                }
            } while (flag == 0);

            returned = check_win(&win);
            if (returned == 0 && win == 'X')
            {
                p1++;
                board();
                printf("\n");
                printf("\t player_1 win \n");
                return;
            }
            else if (returned == 0 && win == 'O')
            {
                p2++;
                board();
                printf("\n");
                printf("\t player_2 win \n");

                return;
            }
            else if (returned == -1)
            {
                printf("\n");
                printf("\t no player  win \n");
                return;
            }

            if (arr[1][1] == '5')
            {
                arr[1][1] = 'O';
            }
            else if (arr[0][2] == '3')
            {
                arr[0][2] = 'O';
            }
            else if (arr[2][0] == '7')
            {
                arr[2][0] = 'O';
            }
            else if (arr[0][0] == '1')
            {
                arr[0][0] = 'O';
            }
            else if (arr[2][2] == '9')
            {
                arr[2][2] = 'O';
            }
            else if (arr[1][0] == '4')
            {
                arr[1][0] = 'O';
            }
            else if (arr[1][2] == '6')
            {
                arr[1][2] = 'O';
            }

            else if (arr[0][1] == '2')
            {
                arr[0][1] = 'O';
            }
            else if (arr[2][1] == '8')
            {
                arr[2][1] = 'O';
            }
            returned = check_win(&win);
            if (returned == 0 && win == 'X')
            {
                p1++;
                board();
                printf("\n");
                printf("\t player_1 win \n");
                return;
            }
            else if (returned == 0 && win == 'O')
            {
                p2++;
                board();
                printf("\n");

                printf("\t player_2 win \n");
                return;
            }
            else if (returned == -1)
            {
                printf("\n");
                printf("\t no player  win \n");
                return;
            }

            board();
        }

        while (returned);
    }
    else if (player == 2)
    {
        do
        {
            board();

            do
            {
                printf("\n");
                printf("\tPlayer 2, enter your move (1-9):  ");
                scanf("%c", &op);
                while (getchar() != '\n')
                    ;
                if (*(*arr + (op - 48) - 1) == op)
                {
                    *(*arr + (op - 48) - 1) = 'O';
                    flag = 1;
                    board();
                }
                else
                {
                    board();
                    printf("\n");
                    printf("\tthis position is selected \n");
                    printf("\tTry again \n");

                    flag = 0;
                }
            } while (flag == 0);
            returned = check_win(&win);
            if (returned == 0 && win == 'X')
            {
                p1++;
                board();
                printf("\n");
                printf("\t player_1 win \n");
                return;
            }
            else if (returned == 0 && win == 'O')
            {
                p2++;
                board();
                printf("\n");

                printf("\t player_2 win \n");
                return;
            }
            else if (returned == -1)
            {
                printf("\n");
                printf("\t no player  win \n");
                return;
            }

            if (arr[1][1] == '5')
            {
                arr[1][1] = 'X';
            }
            else if (arr[0][2] == '3')
            {
                arr[0][2] = 'X';
            }
            else if (arr[2][0] == '7')
            {
                arr[2][0] = 'X';
            }
            else if (arr[0][0] == '1')
            {
                arr[0][0] = 'X';
            }
            else if (arr[2][2] == '9')
            {
                arr[2][2] = 'X';
            }
            else if (arr[1][0] == '4')
            {
                arr[1][0] = 'X';
            }
            else if (arr[1][2] == '6')
            {
                arr[1][2] = 'X';
            }

            else if (arr[0][1] == '2')
            {
                arr[0][1] = 'X';
            }
            else if (arr[2][1] == '8')
            {
                arr[2][1] = 'X';
            }
            board();

            returned = check_win(&win);
            if (returned == 0 && win == 'X')
            {
                p1++;
                board();
                printf("\n");
                printf("\t player_1 win \n");
                return;
            }
            else if (returned == 0 && win == 'O')
            {
                p2++;
                board();
                printf("\n");
                printf("\t player_2 win \n");
                return;
            }
            else if (returned == -1)
            {
                printf("\n");
                printf("\t no player  win \n");
                return;
            }

            board();
        }

        while (returned);
    }
    else
    {
        printf("\t Invalid Number !!\n");
    }
}

int check_win(char *c)
{
    for (int j = 0; j < 3; j++)
    {

        if (arr[j][0] == arr[j][1] && arr[j][0] == arr[j][2])
        {
            *c = arr[j][0];
            return 0;
        }
    }
    for (int j = 0; j < 3; j++)
    {

        if (arr[0][j] == arr[1][j] && arr[0][j] == arr[2][j])
        {
            *c = arr[0][j];
            return 0;
        }
    }
    if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2])
    {
        *c = arr[0][0];
        return 0;
    }
    if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])
    {
        *c = arr[0][2];
        return 0;
    }
    if ((arr[0][0] != '1') && (arr[0][1] != '2') && (arr[0][2] != '3') &&
        (arr[1][0] != '4') && (arr[1][1] != '5') && (arr[1][2] != '6') &&
        (arr[2][0] != '7') && (arr[2][1] != '8') && (arr[2][2] != '9'))
    {
        return -1;
    }
    return 1;
}
void multi_play(void)
{
    char op = 0;
    char win = 0;
    int returned = 0;
    int flag = 0;
    do
    {
        board();

        do
        {

            printf("\n");
            printf("\tPlayer 1, enter your move (1-9):  ");

            scanf("%c", &op);
            while (getchar() != '\n')
                ;
            if (*(*arr + (op - 48) - 1) == op)
            {
                *(*arr + (op - 48) - 1) = 'X';
                flag = 1;
                board();
            }
            else
            {
                board();
                printf("\n");
                printf("\tthis position is selected \n");
                printf("\tTry again \n");
                flag = 0;
            }
        } while (flag == 0);

        returned = check_win(&win);
        if (returned == 0 && win == 'X')
        {
            p1++;
            board();
            printf("\n");
            printf("\t player_1 win \n");
            return;
        }
        else if (returned == 0 && win == 'O')
        {
            p2++;
            board();
            printf("\n");
            printf("\t player_2 win \n");

            return;
        }
        else if (returned == -1)
        {
            printf("\n");
            printf("\t no player  win \n");
            return;
        }

        board();

        do
        {

            printf("\n");
            printf("\tPlayer 2, enter your move (1-9):  ");
            scanf("%c", &op);
            while (getchar() != '\n')
                ;
            if (*(*arr + (op - 48) - 1) == op)
            {
                *(*arr + (op - 48) - 1) = 'O';
                flag = 1;
                board();
            }
            else
            {
                board();
                printf("\n");
                printf("\tthis position is selected \n");
                printf("\tTry again \n");

                flag = 0;
            }
        } while (flag == 0);

        returned = check_win(&win);
        if (returned == 0 && win == 'X')
        {
            p1++;
            board();

            printf("\n");
            printf("\t player_1 win \n");
            return;
        }
        else if (returned == 0 && win == 'O')
        {
            p2++;
            board();

            printf("\n");
            printf("\t player_2 win \n");

            return;
        }
        else if (returned == -1)
        {
            printf("\n");
            printf("\t no player  win \n");
            return;
        }
    } while (returned);
}
