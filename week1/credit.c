#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_number = get_long("Number: ");
    long temp_number = card_number;
    int sum = 0;
    int count = 0;

    while (temp_number > 0)
    {
        int last_digit = temp_number % 10;

        if (count % 2 == 1)
        {
            last_digit *= 2;

            if (last_digit > 9)
            {
                last_digit = (last_digit % 10) + 1;
            }
        }

        sum += last_digit;
        temp_number /= 10;
        count++;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    temp_number = card_number;
    while (temp_number > 100)
    {
        temp_number /= 10;
    }

    if ((temp_number / 10 == 5) && (temp_number % 10 > 0) && (temp_number % 10 < 6) &&(count == 16))
    {
        printf("MASTERCARD\n");
    }
    else if ((temp_number / 10 == 4) && (count == 13 || count ==16))
    {
        printf("VISA\n");
    }
    else if ((temp_number == 34 || temp_number == 37) && (count == 15))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}