#include <stdio.h>
#include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_1_Lecture\\src\\cs50.h"

int main(void)
{
    char c = get_char("Do you agree? ");

    if (c == 'y' || c == 'Y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Not agreed.\n");
    }
    else
    {
        printf("Unknown response. \n");
    }
}