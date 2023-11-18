#include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_1_Lecture\\Problem_set_1\\population\\cs50.h"
#include <stdio.h>

long get_population(void);
long get_desired(void);

int main(void)
{
    // TODO: Prompt for start size
    long size = get_population();

    // TODO: Prompt for end size
    long final = get_desired();
    printf("LLama population size %li, desired LLama population size %li \n", size, final);

    // TODO: Calculate number of years until we reach threshold
    int years = 1;
    while (size < final)
    {
        long new = size / 3 - size / 4;
        // size = (long) size + ((float) size*(1/3-1/4));
        size = size + new;
        printf("Years %i, llama population size %li \n", years, size);
        years++;
    }

    // TOD...
}

long get_population(void)
{
    long population;
    do
    {
        population = get_long("What's llamas population size?");
    } while (population < 9);
    return population;
}

long get_desired(void)
{
    long desired;
    do
    {
        desired = get_long("What's  desired llamas population size? (more than 20)");
    } while (desired < 20);
    return desired;
}