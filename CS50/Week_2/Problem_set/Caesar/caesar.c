// Idea of this task/script is to implement Caesar's encoding/cipher - to rotate each character
// in sentence/message by fixed number of letters (as for their position in the alphabet),
// so only the sender and reciever (knowing the 'key') have means to decrypt what seems to be a radom set of letters

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

    // For each character in the plaintext:
    // Rotate the character if it's a letter

    // for (int i = 0; i < strlen(plaintext); i++)
    for (int i = 0; i < len; i++)
    {
        // printf("Char %c \n", plaintext[i]);
        rotate(plaintext[i], key);
    }

    
}

int get_key(void)
{
    int n;
    do
    {
        n = get_int("Please insert key: ");
    } while (n < 1);
    n = n % 26;
    return n;
}

char rotate(char c, int n)
{
    // int changed_value;
    // check for lowercase/uppercase/other characters in received string:
    if (c >= 'a' && c <= 'z') // 'a' is 97 in ASCII, 'z' is 122
    {
        // return printf("%c is lowercase \n", c);

        // c = (int) c + (int) n;
        // printf("%c int(c): %i \n", c, c);

        if (c + n > 122) // when 'key' (represented by n here) reaches beyond letter 'z'
        {
            char new_c = 97 + (c + n - 122 - 1); // modulo from char c, but implemented here - '-1' to not omit first - 'a' letter
            // return printf("%c is lowercase, int(c): %i \n", new_c, new_c);
            return printf("%c", new_c);
        }
        else
        {
            c = c + n;
        }
        // return printf("%c is lowercase \n", c);
        return printf("%c", c);
    }
    else if (c >= 'A' && c <= 'Z') // 'A' is 65 in ASCII, 'Z' is 90
    {
        if (c + n > 90) // when 'key' (represented by n here) reaches beyond letter 'z'
        {
            char new_c = 65 + (c + n - 90 - 1); // modulo from char c, but implemented here - '-1' to not omit first - 'a' letter
            // return printf("%c is uppercase, int(c): %i \n", new_c, new_c);
            return printf("%c", new_c);
        }
        else
        {
            c = c + n;
        }
        // return printf("Pre-coded: %c is uppercase \n", c);
        return printf("%c", c);
    }
    else
    {
        // return printf("%c is not a letter \n", c);
        return printf("%c", c);
    }
}