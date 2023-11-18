// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_1_Lecture\\Problem_set_1\\Half\\cs50.h"
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
     charge = half();

}

float half(void)
{
    bill = get_float("Bill before tax and tip: ");
    tax = get_float("Sale tax Percent: ");
    tip = get_float("Tip percent: ");
    printf("Bill: %f tax: %f tip: %f", bill, tax, tip);
}