#include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_1_Lecture\\Problem_set_1\\Prime\\cs50.h"
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    } while (min < 1);

    int max;
    do
    {
        max = get_int("Max: ");
    } while (max > 101);

    for (int i = min; i < max + 1; i++)
    {
        if (prime(i))
        {
            printf("%i \n", i);
        }
        // printf("%i \n", i);
    }
}

bool prime(int number)
{
    // for (int i = 2; i < number/2; i++)
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}