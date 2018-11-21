//Number 1 in Review
//Make a function that determines the greatest common divisor between two numbers
#include <stdio.h>

int Great_Common(int Anum, int Bnum)
{
    int smaller; //

    //Just to figure out which one is smaller to set the for loop end condition
    if(Anum >= Bnum)
    {
        smaller = Bnum; //The smaller one would be B
    }
    else
    {
        smaller = Anum;
    }

    int i; // Stepping variable for the loop
    int divisor;//The greatest common divisor
    for(i = 1; i <= smaller; i=i+1) //Begin from 1 for mod, then go until you reach the smaller number
    {
        if((Anum%i == 0) && (Bnum%i == 0)) //If the number is divisible by both numbers
        {
            divisor = i; //Reassign if there is a higher number
        }
    }
    return divisor;//Send back that greater
}

int main()
{
    //Input the two numbers here
    int A = 11;
    int B = 11;
    int divisor = Great_Common(A,B);
    //Report the value
    printf("The greatest common divisor between %i and %i is:\n\n%i\n",A,B,divisor);
}
