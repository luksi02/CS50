#include <stdio.h>
#include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_1_Lecture\\src\\cs50.h"

int main(void)
{
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is not less than y\n");
    }
    else
    {
        printf("x and y are equal\n");
    }
}