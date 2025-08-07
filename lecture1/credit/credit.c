#include <cs50.h>
#include <stdio.h>

long get_number(void);
void judge(long number);
bool judgevalid(long number);

int main(void)
{
    long number=get_number();
    judge(number);
}

long get_number(void)
{
    long n;
    n=get_long("Number:");
    return n;
}

void judge(long number)
{
   if(judgevalid(number))
   {
    int length=0;
    do
    {
        number=number/10;
        length=length+1;
    }
    while(number>=100);
    length=length+2;

    if(number==34||number==37)
    {
        if(length==15)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if(number>=40&&number<50)
    {
        if((length==13||length==16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if(number>=51&&number<=55)
    {
        if(length==16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
   }
   else
   {
    printf("INVALID\n");
   }
}

bool judgevalid(long number)
{
    int i=0,j=0,k=0;
    do
    {
        i=number%10;
        j=number/10%10;
        if(2*j>=10)
        {
            j=2*j%10+1;
        }
        else
        {
            j=2*j;
        }
        k=k+i+j;
        number=number/100;
        // printf("i: %d\n",i);
        // printf("j: %d\n",j);
        // printf("k: %d\n",k);
    }
    while (number!=0);
    // printf("k: %d\n",k);
    if (k%10==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
