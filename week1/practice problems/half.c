// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    tax /= 100;
    float tip_decimal = (float) tip / 100;

    float taxed_bill = bill * (1 + tax);

    float tip_amount = taxed_bill * tip_decimal;

    float total_amount = taxed_bill + tip_amount;

    return total_amount / 2;
}
