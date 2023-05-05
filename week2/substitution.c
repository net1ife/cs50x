#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool is_valid_key(string key);
char encrypt_char(char plain_char, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    if (!is_valid_key(key))
    {
        printf("Key must contain 26. unique alphabetic characters. \n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        printf("%c", encrypt_char(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

bool is_valid_key(string key)
{
    int length = strlen(key);
    if (length != 26)
    {
        return false;
    }

    int letter_count[26] = {0};

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = toupper(key[i]) - 'A';
        letter_count[index]++;

        if (letter_count[index] > 1)
        {
            return false;
        }
    }

    return true;
}

char encrypt_char(char plain_char, string key)
{
    if (isalpha(plain_char))
    {
        char base = isupper(plain_char) ? 'A' : 'a';
        int index = plain_char - base;
        return isupper(plain_char) ? toupper(key[index]) : tolower(key[index]);
    }
    else
    {
        return plain_char;
    }
}