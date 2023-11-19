#include <stdio.h>
#include <string.h>
#include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_2\\Problem_set\\cs50.h"

int main(void)
{
    string input = get_string("Message to code: \n");

    int len = strlen(input);

    for (int i = 0; i < len; i++)
    {
        int ascii_value = (int)input[i];
        printf("Char number %i, ASCII value: %i \n", i, ascii_value);
        int divider = 1;

        for (int j = 1; j <= 8; j++)
        {
            // int divider =
            if (ascii_value % divider != 0)
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
            divider = divider * 2;
            printf(": bit value, Byte place no %i, divider: %i \n", j, divider);
        }
    }
}