#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randomAI(char array[], int size);
int main()
{
    int numSum = 0;
    char player = 'x';
    char ai = 'o';
    char placeNumber[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    do
    {
        int number;
        scanf("%d", &number);
        printf("%d", number);
        int random = randomAI(placeNumber, 9);

        if (number >= 0 && number < 9)
        {
            if (placeNumber[number] != ' ')
            {
                printf("Repeat Already taken");
            }
            else
            {
                placeNumber[number] = player;
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
            }
        }

        else
        {
            printf("Put number between 0 and 8");
        }

    } while (numSum < 9);
    return 0;
}

int randomAI(char array[], int size)
{
    srand(time(NULL));
    int random = rand() % 9;
    return random;
}
