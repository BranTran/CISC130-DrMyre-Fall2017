//Number 6 in Review
//Recursive Function that sum even numbers in an array
#include <stdio.h>

int sumEvens(int array[], int size)
{
    int value;
    if(size == 0)//Base case
    {
        value = 0;
    }
    else
    {
        value = sumEvens(array, size-1);// Goes from amount of indicies to 1
        if(array[size-1]%2 != 1)//Will call 0 to size-1
        {
            value = value + array[size-1];
        }
    }
    return value;
}

int main()
{
    int size = 10;
    int array[size];
    int i;
    srand((unsigned)time(NULL));
    for(i=0;i<size;i=i+1)
    {
        array[i]=rand()%100;
    }
    int sum = sumEvens(array,size);
    printf("Given array:\n\n");
    for(i=0;i<size;i=i+1)
    {
        printf("%i, ",array[i]);
    }
    printf("\n\n");
    printf("%i is the sum of this array.\n",sum);

}
