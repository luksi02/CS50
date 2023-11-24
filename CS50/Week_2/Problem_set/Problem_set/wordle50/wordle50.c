// The idea of this task is to re-create famous web-game 'Wordle50'.
// Idea of the game is to guess the 5-letter code word - in 6 guesses, in which
// the player has to guess - when player uses charcter that is in code word,
// it is marked as green (if it's in correct place) or yellow (if its in wrong
// place). Otherwise the character is marked as red.

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_2\\cs50.h"

string get_answer(void);

int main(void)
{
    string codeworld = "world"; // simple example

    printf("You have 6 tries to guess 5-letter codeword, good luck! \n");

    for (int i = 1; i < (strlen(codeworld) + 2); i++)
    {
        string answer = get_answer();
        int win = strcmp(codeworld, answer);
        if (win == 0) // if words are equal => 0
        {
            return printf("Guess no. %i You guessed the codeword! Congratulations!", i);
        }
        else
        {
            for (int j = 0; j < strlen(codeworld); j++)
            {
                for (int k = 0; k < strlen(codeworld); k++)
                {
                    if (answer[j] == codeworld[j])
                    {
                        printf("1"); // as letter is in right place
                    }
                    else if (answer[j] == codeworld[k])
                    {
                        printf("-"); // as letter is in word, but wrong place
                    }
                    else
                    {
                        printf("0");
                    }
                }
                printf("Guess no. %i word: %s \n", i, answer);
            }
        }
    }
    printf("Reached limit of 6 tries, you lost!");
}

string get_answer(void)
{
    string key;
    int n;
    int onlyLetters;
    do
    {
        onlyLetters = 0;
        key = get_string("Please provide your guess: ");
        n = strlen(key);

        for (int i = 0; i < n; i++)
        {
            if (isalpha(key[i]) == 0) // check for letters
            {
                return onlyLetters = 0;
            }
            else
            {
                onlyLetters = 1;
            }
        }

    } while (n != 5 && !onlyLetters);
    return key;
}