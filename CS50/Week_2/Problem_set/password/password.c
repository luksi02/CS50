// The idea of this task is to validate user-provided password
//  - the password supplied by user should contain at least one
// lowercase letter, one uppercase letter, a number, and a symbol

#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_2\\cs50.h"

int main(void)
{
    bool isLowercase = false;
    bool isUppercase = false;
    bool isNumber = false;
    bool isSpecialCharacter = false;

    string password = get_string("Enter your password: ");

    int len = strlen(password);

    if (len < 8)
    {
        printf("Password is too short! \n");
        return 1;
    }

    for (int i = 0; i < len; i++)
    {
        if (islower(password[i]))
        {
            isLowercase = true;
            break;
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (isupper(password[i]))
        {
            isUppercase = true;
            break;
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (isdigit(password[i]))
        {
            isNumber = true;
            break;
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (!isalnum(password[i]))
        {
            isSpecialCharacter = true;
            break;
        }
    }

    if (isLowercase && isUppercase && isNumber && isSpecialCharacter)
    {
        return printf("Your password is valid!");
    }
    else
    {
        return printf("Your password needs at least one uppercase letter, lowercase letter, number and special character!");
    }
}
