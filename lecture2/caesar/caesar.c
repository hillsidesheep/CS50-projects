#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

bool only_digits(string key);
char rotate(char letter, int key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // only_digits
        if (only_digits(argv[1]))
        {
            // get string
            string plaintext = get_string("plaintext:  ");
            // ciphertext
            printf("ciphertext: ");
            // rotate
            int n = 0;
            while (plaintext[n] != '\0')
            {
                printf("%c", rotate(plaintext[n], atoi(argv[1])));
                n++;
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool only_digits(string key)
{
    int n = 0;
    while (key[n] != '\0')
    {
        if (key[n] <= '0' || key[n] >= '9')
        {
            return false;
        }
        n++;
    }
    return true;
}

char rotate(char letter, int key)
{
    int c = 0, p = 0;
    if (letter >= 'a' && letter <= 'z')
    {
        p = letter - 'a';
        c = (p + key) % 26;
        letter = 'a' + c;
    }
    else if (letter >= 'A' && letter <= 'Z')
    {
        p = letter - 65;
        c = (p + key) % 26;
        letter = 'A' + c;
    }
    return letter;
}
