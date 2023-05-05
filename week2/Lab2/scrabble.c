#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(const char *word);

int main(void)
{
    // Get input words from both players
    char word1[256];
    char word2[256];
    printf("Player 1: ");
    scanf("%s", word1);
    printf("Player 2: ");
    scanf("%s", word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(const char *word)
{
    // Initialize the score
    int score = 0;

    // Iterate through each character in the word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Ensure the character is an alphabet letter
        if (isalpha(word[i]))
        {
            // Convert the character to its upper case form
            char upper_char = toupper(word[i]);

            // Calculate the score for the character
            int char_score = POINTS[upper_char - 'A'];

            // Add the character score to the total score
            score += char_score;
        }
    }

    // Return the total score
    return score;
}
