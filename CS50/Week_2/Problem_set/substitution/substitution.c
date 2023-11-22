// Idea of this task/script is to implement encoding messages by key -
// 26-character-long set of letters (as representation of alphabet), so message
// is respresnted as their substitute in the key (as in alphabetical order)

#include <stdio.h>
#include <string.h>
#include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_2\\cs50.h"

// example key: 'qwertyuiopasdfghjklzxcvbnm'

string get_key(void);
// char rotate(char c, int n);

int main(void)
{
    // Implement protection for doubling letters in code... but later xd
    string key = get_key();
    printf("Key: %s \n", key);

    // Prompt user for plaintext
    string plaintext = get_string("Insert text to encode: ");
    printf("Plaintext: %s \n", plaintext);

    int len = strlen(plaintext);
    printf("Length: %i \n", len);

    // for (int i = 0; i < strlen(plaintext); i++)
    for (int i = 0; i < len; i++)
    {
        // to simplify just lowercase for now - '97' stands for 'a' in ASCII
        int index = plaintext[i] - 97;
        printf("Plaintext char: %c code char: %c \n", plaintext[i], key[index]);
        // rotate(plaintext[i], key);
    }
}

// TODO: 1 Protect code from recurring letters,
// 2. translate only letters
// 3. handle uppercase

string get_key(void)
{
    int n;
    string key;
    do
    {
        key = get_string("Please insert 26-character key: ");
        n = strlen(key);
    } while (n != 26);
    return key;
}
