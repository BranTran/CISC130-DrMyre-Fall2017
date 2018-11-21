//Number 2 in Review
//Make a recursive Fibonacci
#include <stdio.h>

int Fibonacci(int num) //Code that takes in n and returns the "nth" Fibonacci number
{
    int value;
    if(num == 0)//Base Case
    {
        value = 0;
    }
    else if (num == 1)
    {
        value = 1;
    }
    else //General Case
    {
        value =  Fibonacci(num-2)+Fibonacci(num-1); // Fibonacci Formula
    }
    return value;
}

void CountDown(int num)//Recursive Loop that calls all numbers n to 0
{
    int value;
    if(num == 0)
    {
        value = Fibonacci(0);
    }
    else
    {
        CountDown(num-1);
        value = Fibonacci(num);
    }

    printf("%i, ", value);
}

/** THIS FULFILLS THE PROBLEM, ALBEIT UNCONVENTIONAL AND MALPRACTICE
void CountDown(int num)//Recursive Loop that calls all numbers n to 0
{
    CREATE A CALCULATION FUNCTION INSIDE OUR FUNCTION
    int Fibonacci(int num) //Code that takes in n and returns the "nth" Fibonacci number
    {
        int value;
        if(num == 0)//Base Case
        {
            value = 0;
        }
        else if (num == 1)
        {
            value = 1;
        }
        else //General Case
        {
            value =  Fibonacci(num-2)+Fibonacci(num-1); // Fibonacci Formula
        }
        return value;
    }
    END FUNCTION


    int value;
    if(num == 0)
    {
        value = Fibonacci(0);
    }
    else
    {
        CountDown(num-1);
        value = Fibonacci(num);
    }

    printf("%i, ", value);
}*/

int main()
{
    int num;
    printf("Enter a how many Fibonacci numbers you would like: ");
    scanf(" %i", &num);

    CountDown(num);
}
