#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt for Text
    string text = get_string("Text: ");
    // printf("%s\n",text);
    // count letters
    int letters = count_letters(text);
    // printf("%i letters\n",letters);
    // count word
    int words = count_words(text);
    // printf("%i words\n",words);
    // count word
    int sentences = count_sentences(text);
    // printf("%i sentences\n",sentences);
    // index
    float L = letters / 1.0 / words * 100.0, S = sentences / 1.0 / words * 100.0;
    // printf("L=%f,S=%f\n",L,S);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int) index;
    if ((index - grade) >= 0.5)
    {
        grade += 1;
    }
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int n = 0, letters = 0;
    while (text[n] != '\0')
    {
        if ((text[n] >= 'a' && text[n] <= 'z') || (text[n] >= 'A' && text[n] <= 'Z'))
        {
            letters++;
        }
        n++;
    }
    return letters;
}

int count_words(string text)
{
    int n = 0, words = 1;
    while (text[n] != '\0')
    {
        if (text[n] == ' ')
        {
            words++;
        }
        n++;
    }
    return words;
}

int count_sentences(string text)
{
    int n = 0, sentences = 0;
    while (text[n] != '\0')
    {
        if (text[n] == '.' || text[n] == '?' || text[n] == '!')
        {
            sentences++;
        }
        n++;
    }
    return sentences;
}
