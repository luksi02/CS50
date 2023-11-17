#include <stdio.h>
#include <stdbool.h>
// #include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_1_Lecture\\src\\cs50.h"

int main(void)
{
    int i = 0;
    while (i < 3)
    {
        printf("meow \n");
        i++;
    }

    for (int x = 0; x < 3; x++)
    {
        printf("meow with for-loop\n");
        i++;
    }

    while (true)
    {
        printf("Forever meow! \n");
    }
}