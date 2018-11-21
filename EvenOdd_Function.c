//Number 8 in Review
//Determine if integer is even or odd
#include <stdio.h>

void EvenOdd(int num)
{
    int pos_num;
    if(num < 0)//This is to prevent issues with negative modulus
    {
        pos_num = num*(-1);
    }
    else
    {
        pos_num = num;
    }


    if(pos_num%2 == 1)
    {
        printf("The number %i is odd.\n",num);
    }
    else
    {
        printf("The number %i is even.\n",num);
    }
}

int main()
{
    int num;
    printf("Please enter a number: ");
    scanf(" %i", &num);
    EvenOdd(num);
}
