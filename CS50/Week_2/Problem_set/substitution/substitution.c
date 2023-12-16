// Idea of this task/script is to implement encoding messages by key -
// 26-character-long set of letters (as representation of alphabet), so message
// is respresnted as their substitute in the key (as in alphabetical order)

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_2\\cs50.h"

// example key: 'qwertyuiopasdfghjklzxcvbnm'

string get_key(void);
int isUniqueLetter(string input);

int main(void)
{
    string key = get_key();
    printf("Key: %s \n", key);

    // string key = "qwertyuiopasdfghjklzxcvbnm";

    string plaintext = get_string("Insert text to encode: ");
    printf("Plaintext: %s \n", plaintext);

    int len = strlen(plaintext);
    printf("Length: %i \n", len);

    for (int i = 0; i < len; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            int index = plaintext[i] - 97;
            char coded_char = tolower(key[index]);
            printf("Plaintext char: %c code char: %c \n", plaintext[i], coded_char);
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            int index = plaintext[i] - 65;
            char coded_char = toupper(key[index]);
            printf("Plaintext char: %c code char: %c \n", plaintext[i], coded_char);
        }
        else
        {
            printf("Plaintext char: %c", plaintext[i]);
        }
    }
}

string get_key(void)
{
    int n;
    string key;
    int isUnique;

    do
    {
        key = get_string("Please insert 26-character key: ");
        n = strlen(key);

        isUnique = isUniqueLetter(key);

    } while (n != 26 && !isUnique);
    return key;
}

int isUniqueLetter(string input)
{
    int charSet[26] = {};

    for (int i = 0; i < strlen(input); i++)
    {
        char ch = tolower(input[i]);

        if (isalpha(ch))
        {
            int charValue = ch - 'a';

            if (charSet[charValue] > 0)
            {
                return 0;
            }

            charSet[charValue] = 1;
        }
    }
}
