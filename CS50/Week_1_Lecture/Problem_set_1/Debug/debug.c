#include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_1_Lecture\\Problem_set_1\\Debug\\cs50.h"

int main(void)
{
    // Ask for your name and where live
    string name = get_string("What is your name? ");
    string home = get_string("Where do you live? ");
    printf("Hello, %s, from %s! \n", name, home);
}