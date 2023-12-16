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
    string codeworld = "world"; // simple example

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

        printf("%s \n '1' as correct letter at correct place, '-' as misplaced letter, '0' as wrong letter \n", feedback);

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
    // Initialize arrays to track correct and misplaced letters
    bool correctLetter[100] = {false};
    bool misplacedLetter[100] = {false};

    // Check for correct letters and mark them as '1'
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == guess[i])
        {
            feedback[i] = '1';
            correctLetter[i] = true;
        }
    }

    // Check for misplaced letters and mark them as '-'
    for (int i = 0; i < strlen(word); i++)
    {
        if (!correctLetter[i])
        {
            for (int j = 0; j < strlen(guess); j++)
            {
                if (!correctLetter[j] && !misplacedLetter[j] && word[i] == guess[j])
                {
                    feedback[i] = '-';
                    misplacedLetter[j] = true;
                    break;
                }
            }
        }
    }

    // Mark incorrect letters as '0'
    for (int i = 0; i < strlen(word); i++)
    {
        if (!correctLetter[i] && !misplacedLetter[i])
        {
            feedback[i] = '0';
        }
    }

    return feedback;
}