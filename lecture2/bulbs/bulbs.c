#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string message = get_string("Message: ");
    int bit[8] = {0};
    int n = 0, i;
    while (message[n] != '\0')
    {
        i = 1;
        do
        {
            bit[8 - i] = message[n] % 2;
            message[n] /= 2;
            i++;
        }
        while (message[n] != 0);
        for (i = 0; i < 8; i++)
        {
            print_bulb(bit[i]);
            bit[i] = 0;
        }
        printf("\n");
        n++;
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
