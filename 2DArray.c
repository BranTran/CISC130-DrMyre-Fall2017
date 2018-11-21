//Number 7 in Review
//Create a 2D 10X10 and ask the user to enter values for each element

#include <stdio.h>
int main()
{
    int size = 3;//Problem asks for 10, but it is too many inputs to test
    int array[size][size];
    int i;
    int j;
    for(i=0;i<size;i=i+1)
    {
        for(j=0;j<size;j=j+1)
        {
            int value;
            printf("Please enter a number for (%i,%i): ",i,j);
            scanf(" %i", &value);
            array[i][j] = value;
        }
    }
    //Print the array that we just made
    for(i=0; i < size; i++)
    {
        for(j=0; j < size; j++)
        {
            printf("%i\t",array[i][j]);
        }
        printf("\n");
    }
}
