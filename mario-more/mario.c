#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Give a height between 1 to 8 \n");
    int space = 0;
    int brick = 0;
    while (height < 1 || height > 8)
    {
        height = get_int("Give a height between 1 to 8 \n");
    }

    for (int i = 0; i < height; i++)
    {
        // determine space and brick nums
        space = height - (i + 1);
        brick = height - space;

        // print space
        for (int j = 0; j < space; j++)
        {
            printf(" ");
        }

        // print #
        for (int k = 0; k < brick; k++)
        {
            printf("#");
        }

        printf("  ");

        // print #
        for (int k = 0; k < brick; k++)
        {
            printf("#");
        }

        // next line
        printf("\n");
    }
}