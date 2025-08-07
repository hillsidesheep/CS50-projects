#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int n);

int main(void)
{
    int n=get_size();
    print_grid(n);
}

int get_size(void)
{
    int n;
    do
    {
        n=get_int("Height:");
    }
    while(n<1||n>8);
    return n;
}

void print_grid(int n)
{
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            printf(" ");
        }
        for(int k=0;k<i+1;k++)
        {
            printf("#");
        }
        printf("  ");
        for(int j=0;j<i+1;j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
