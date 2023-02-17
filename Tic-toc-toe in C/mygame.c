#include <stdio.h>
#include <stdlib.h>

void printBoard(char board[3][3]);
int assignBoard(char board[3][3], int playerTurn);
int checkWin(char board[3][3], char mark);

int main()
{
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};

    printf("\nYour mark is 'X'\nSystem mark is 'O'\n");
    while (checkWin(board, 'X') && checkWin(board, 'O'))//return 1 if not wins
    {
        printf("\nPlayer turn !\n");
        if (assignBoard(board, 1))//return 1 if assigned!;
        {
            printBoard(board);
            if(checkWin(board,'X')&&checkWin(board,'O'))
            {
                // check for a tie
                if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' &&
                    board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' &&
                    board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')
                {
                    printBoard(board);
                    printf("\nIt's a tie!\n");
                    break;
                }
                printf("\nSystem Enters!\n");
                assignBoard(board, 2);
                printBoard(board);
            }
            else
            {
                break;
            }
        }
        else
        {
            continue;
        }
    }
}

int assignBoard(char board[3][3], int playerTurn)
{
    char mark = (playerTurn == 1) ? 'X' : 'O';
    int i, j, choice;
    if (playerTurn == 2)
    {
        do
        {
            i = rand() % 3;
            j = rand() % 3;
        } while (board[i][j] == 'O' || board[i][j] == 'X');
    }
    else
    {
        printf("\nEnter a number[1-9] : ");
        scanf("%d", &choice);

        i = (choice - 1) / 3;
        j = (choice - 1) % 3;

        if (board[i][j] == 'O' || board[i][j] == 'X')
        {
            printf("\nPlace is Already Taken! enter other numer!\n");
            return 0;
        }
    }

    board[i][j] = mark;

    return 1;
}

int checkWin(char board[3][3], char mark)
{
    // chechk for rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark)
        {
            if (mark == 'X')
            {
                printf("\nPlayer Wins!\n");
            }
            else
            {
                printf("\nSystem Wins!\n");
            }
            return 0;
        }
    }
    // chechk for columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)
        {
            if (mark == 'X')
            {
                printf("\nPlayer Wins!\n");
            }
            else
            {
                printf("\nSystem Wins!\n");
            }
            return 0;
        }
    }

    // check for diagonals
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark)
    {
        if (mark == 'X')
        {
            printf("\nPlayer Wins!\n");
        }
        else
        {
            printf("\nSystem Wins!\n");
        }
        return 0;
    }
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
    {
        if (mark == 'X')
        {
            printf("\nPlayer Wins!\n");
        }
        else
        {
            printf("\nSystem Wins!\n");
        }
        return 0;
    }

    return 1;
}

void printBoard(char board[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);

            if (j < 2)
            {
                printf("|");
            }
        }
        if (i < 2)
        {
            printf("\n----------\n");
        }
    }
    printf("\n\n");
}
