#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char combination(char place[]);
int randomAI(char array[], int size);

int main()
{
    int numSum = 0;
    char player = 'X';
    char ai = 'O';
    char placeNumber[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    do
    {
        char winner = combination(placeNumber);
        int number;
        if (winner != ' ')
        {
            printf("Winner %c", winner);
            break;
        }
        printf("\nPrint number between 0 and 8 ");
        scanf("%d", &number);
        if (number >= 0 && number < 9)
        {
            if (placeNumber[number] != ' ')
            {
                printf("Repeat Already taken");
            }
            else
            {
                placeNumber[number] = player;
                int random = randomAI(placeNumber, 9);

                if (placeNumber[random] != ' ')
                {
                    random = randomAI(placeNumber, 9);
                }
                else
                {
                    placeNumber[random] = ai;
                }

                numSum++;
                printf("\n");
                printf(" %c | %c | %c\n", placeNumber[0], placeNumber[1], placeNumber[2]);
                printf("-----------\n");
                printf(" %c | %c | %c\n", placeNumber[3], placeNumber[4], placeNumber[5]);
                printf("-----------\n");
                printf(" %c | %c | %c\n", placeNumber[6], placeNumber[7], placeNumber[8]);
                printf("\n");
                // printf("%d", numSum);
                if (numSum == 5)
                {
                    printf("Draw");
                    break;
                }
            }
        }

        else
        {
            printf("Put number between 0 and 8");
        }

    } while (numSum < 9);
    return 0;
}

char combination(char place[])
{
    for (int i = 0; i < 9; i += 3)
    {
        if ((place[i] == place[i + 1] && place[i + 1] == place[i + 2]) && (place[i + 1] == 'X' || place[i + 1] == 'O'))
        {
            return place[i + 1];
        }
    }
    for (int j = 0; j < 9; j += 1)
    {
        if ((place[j] == place[j + 3] && place[j + 3] == place[j + 6]) && (place[j + 3] == 'X' || place[j + 3] == 'O'))
        {
            return place[j + 3];
        }
    }
    if (((place[0] == place[4] && place[4] == place[8]) && (place[4] == 'X' || place[4] == 'O')) ||
        ((place[2] == place[4] && place[4] == place[6]) && (place[4] == 'X' || place[4] == 'O')))
    {
        return place[4];
    }
    return ' ';
}

int randomAI(char array[], int size)
{
    srand(time(NULL));
    int random;
    int randomCount = 0;
    do
    {
        random = rand() % size;
        randomCount++;
        if (randomCount > size)
        {
            break;
        }

    } while (array[random] != ' ');

    return random;
}
