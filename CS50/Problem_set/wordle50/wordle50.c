// The idea of this task is to re-create famous web-game 'Wordle50'.
// Idea of the game is to guess the 5-letter code word - in 6 guesses, in which
// the player has to guess - when player uses charcter that is in code word,
// it is marked as green (if it's in correct place) or yellow (if its in wrong
// place). Otherwise the character is marked as red. Or, in my case:
// '1' as correct letter at correct place, '-' as misplaced letter, '0' as wrong letter

#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_2\\cs50.h"

string get_answer(void);

string checkLetters(string word, string guess, string feedback);

int main(void)
{
    string codeworld = "guess"; // simple example

    printf("You have 6 tries to guess 5-letter codeword, good luck! \n");

    int tries = 0;

    do
    {
        string answer = get_answer();
        int isCorrect = strcmp(codeworld, answer);

        tries++;

        printf("%i. your guess, your word: \n%s \n", tries, answer);

        if (isCorrect == 0) // if words are equal => 0
        {
            return printf("Guess no. %i You guessed the codeword! Congratulations!", tries);
        }

        char feedback[strlen(codeworld)];

        checkLetters(codeworld, answer, feedback);

        int len = strlen(feedback);

        printf("%s \n'1' as correct letter at correct place, '-' as misplaced letter, '0' as wrong letter \n", feedback);

    } while (tries < (strlen(codeworld) + 1));

    if (tries == (strlen(codeworld) + 1))
    {
        printf("Reached limit of 6 tries, you lost!");
    }

    return 0;
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

string checkLetters(string word, string guess, string feedback)
{
    int charCount[128] = {0};

    for (int i = 0; i < strlen(word); i++)
    {
        charCount[word[i]]++;
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == guess[i]) // Checking for letters in right place
        {
            feedback[i] = '1';
            charCount[guess[i]]--; // Decrement count for correct letter - case there's more than one
        }
        else if (charCount[guess[i]] > 0) // Checking for misplaced letters
        {
            feedback[i] = '-';
            charCount[guess[i]]--; // Decrement count for misplaced letter - case there's more than one
        }
        else
        {
            feedback[i] = '0';
        }
    }

    return feedback;
}