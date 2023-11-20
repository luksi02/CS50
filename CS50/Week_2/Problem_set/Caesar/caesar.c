#include <stdio.h>
#include <string.h>
#include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_2\\cs50.h"

int get_key(void);
char rotate(char c, int n);

int main(void)
{
    // Make sure program was run with just one command-line argument
    int key = get_key();
    printf("Key: %i \n", key);
    // SO FAR SO GOOD!

    // Make sure every character in argv[1] is a digit --> get_key() handles this, am I wrong?
    // Convert argv[1] from a `string` to an `int` --> get_key() handles this, am I wrong?

    // Prompt user for plaintext
    string plaintext = get_string("Insert text to encode: ");
    printf("Plaintext: %s \n", plaintext);

    int len = strlen(plaintext);
    printf("Length: %i \n", len);

    // for (int i = 0; i < strlen(plaintext); i++)
    for (int i = 0; i < len; i++)
    {
        // printf("Char %c \n", plaintext[i]);
        rotate(plaintext[i], key);
    }

    // For each character in the plaintext:

    // Rotate the character if it's a letter
}

int get_key(void)
{
    int n;
    do
    {
        n = get_int("Please insert key: ");
    } while (n < 1);
    return n;
}

char rotate(char c, int n)
{
    // check for lowercase/uppercase/other characters in received string:
    if (c >= 'a' && c <= 'z')
    {
        return printf("%c is lowercase \n", c);
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return printf("%c is uppercase \n", c);
    }
    else
    {
        return printf("%c is not a letter \n", c);
    }
}