#include <cs50.h>
#include <stdio.h>

int star_size(void);
int end_size(int star_s);
int calculate_year(int star_s,int end_s);

int main(void)
{
    // TODO: Prompt for start size
    int star_s=star_size();
    // TODO: Prompt for end size
    int end_s=end_size(star_s);
    // TODO: Calculate number of years until we reach threshold
    int year=calculate_year(star_s,end_s);
    // TODO: Print number of years
      printf("Years: %i", year);
}

int star_size(void)
{
    int n;
    do
    {
        n = get_int("Star size: ");
    }
    while (n < 9);
    return n;
}

int end_size(int star_s)
{
    int n;
    do
    {
        n = get_int("End size: ");
    }
    while(n<star_s);
    return n;
}

int calculate_year(int star_s,int end_s)
{
    int born=0,die=0,year=0;
    while (star_s<end_s)
    {
        born = star_s/3;
        die = star_s/4;
        star_s = star_s+born-die;
        year++;
    }
    return year;
}
