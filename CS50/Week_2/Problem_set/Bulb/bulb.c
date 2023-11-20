#include <stdio.h>
#include <string.h>
// #include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_2\\Problem_set\\cs50.h"
// #include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_2\\Problem_set\\Bulb\\cs50.h"
#include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_2\\cs50.h"

int main(void)
{
    string input = get_string("Message to code: \n");

    int len = strlen(input);

    for (int i = 0; i < len; i++)
    {
        int ascii_value = (int)input[i];

        // printf("Char number %i, ASCII value: %i \n", i, ascii_value); // WORKS FINE!
        int divider = 128;

        for (int j = 1; j <= 8; j++)
        {

            if (ascii_value >= divider)
            {
                printf("1");
                ascii_value = ascii_value - divider;
            }
            else
            {
                printf("0");
            }
            divider = divider / 2;
            // WORKS!
            // printf(": bit value, Byte place no %i, divider: %i \n", j, divider);
        }
        printf("\n");
        // WORKS FINE!
    }
}