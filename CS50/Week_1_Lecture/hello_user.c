#include <stdio.h>
#include "C:\\Users\\Luksi02\\Desktop\\CS50\\src\\cs50.h"

int main(void)
{
    // printf("Why my libraries dont work? Configuration is super fun!\n");

    string answer = get_string("What's your first name? ");
    string answer_2 = get_string("What's your last name? ");
    printf("Hello, %s  %s", answer, answer_2);
}