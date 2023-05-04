// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

string replace(string input);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    string converted_word = replace(argv[1]);

    printf("%s\n", converted_word);

    free(converted_word);

    return 0;
}

string replace(string input)
{
    int len = strlen(input);
    char* output = malloc(len + 1);

    strcpy(output, input);

    for (int i = 0; i < len; i++)
    {
        char c = input[i];

        switch (c)
        {
            case 'a':
            case 'A':
                input[i] = '6';
                break;
            case 'e':
            case 'E':
                input[i] = '3';
                break;
            case 'i':
            case 'I':
                input[i] = '1';
                break;
            case 'o':
            case 'O':
                input[i] = '0';
                break;
            case 'u':
            case 'U':
                break;
        }
    }

    return input;
}