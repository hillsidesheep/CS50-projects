#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

bool valid_key(string key);
char rotate(char letter, string key);

int main(int argc, const string argv[])
{
    if (argc == 2)
    {
        // valid_key
        if (valid_key(argv[1]))
        {
            // printf("%s\n",argv[1]);
            // get plaintext
            string plaintext = get_string("plaintext:  ");
            // print
            printf("ciphertext: ");
            // rotate
            int n = 0;
            while (plaintext[n] != '\0')
            {
                printf("%c", rotate(plaintext[n], argv[1]));
                n++;
            }
            printf("\n");
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

bool valid_key(string key)
{
    int num = 0;
    string characters[26] = {0};
    while (key[num] != '\0')
    {
        if ((key[num] >= 'a' && key[num] <= 'z') || (key[num] >= 'A' && key[num] <= 'Z'))
        {
            num++;
        }
        else
        {
            return false;
        }
    }
    if (num == 26)
    {
        for (int i = 0; i < 25; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                if (key[i] == key[j])
                    return false;
            }
        }
        return true;
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
}

char rotate(char letter, string key)
{

    int n = 0;
    if (letter >= 'a' && letter <= 'z')
    {
        n = letter - 'a';
        if (islower(key[n]))
        {
            return key[n];
        }
        else
        {
            return (key[n] + 32);
        }
    }
    else if (letter >= 'A' && letter <= 'Z')
    {
        n = letter - 'A';
        if (islower(key[n]))
        {
            return (key[n] - 32);
        }
        else
        {
            return key[n];
        }
    }
    else
        return letter;
}
