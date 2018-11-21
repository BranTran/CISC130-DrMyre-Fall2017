//Number 4 in Review
//Create a recursive function that prints out the content of an in
#include <stdio.h>
#include <math.h>

void Recurse_Print(int array[], int size)
{
    if (size == 1)//Base Case
    {
        //Do nothing
    }
    else // General case
    {
        Recurse_Print(array,size-1);//Edit the size to get closer to the base case recurse from size to 1
    }

    printf("%i ",array[size-1]);//Builds all scopes then prints from the collapse back (gets to 0 and goes back to size-1)
}

int main()
{
    int size = 12;//Setting up the size
    int array[size];

    //Just fill it with random numbers
    int i;
    srand((unsigned)time(NULL));
    for(i=0; i<size; i=i+1)
    {
        array[i] = rand()%10;
    }

    /** Use the function **/
    Recurse_Print(array,size);
}
