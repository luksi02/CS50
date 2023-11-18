// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include "C:\\Users\\Luksi02\\Desktop\\CS50\\Week_1_Lecture\\Problem_set_1\\Half\\cs50.h"
#include <stdio.h>

float half(float bill, float tax, float tip);

int main(void)
{
    float bill = get_float("Bill before tax and tip: ");
    float tax = get_float("Sale tax Percent: ");
    float tip = get_float("Tip percent: ");

    printf("Bill: %.2f tax: %.2f tip: %.2f\n", bill, tax, tip);

    // float charge = (bill + bill*tax/100 + bill*tip/100)/2;

    float charge2 = half(bill, tax, tip);

    // printf("You owe each %.2f \n", charge);
    printf("You owe each $%.2f \n", charge2);
}

float half(float bill, float tax, float tip)
{
    float totalCharge = bill + bill * tax / 100 + bill * tip / 100;
    return totalCharge / 2;
}