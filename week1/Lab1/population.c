#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size;
    do
    {
        start_size = get_int("Enter the starting population size: ");
    }
    while (start_size < 9);

    int end_size;
    do
    {
        end_size = get_int("Enter the ending population size: ");
    }
    while (end_size < start_size);

    int years = 0;
    while (start_size < end_size)
    {
        int new_llamas = start_size / 3;
        int old_llamas = start_size / 4;

        start_size = start_size + new_llamas - old_llamas;

        years++;
    }

    printf("Years: %i\n", years);
}
