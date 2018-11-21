//Number 3 in Review
//Write a function that checks if a string contains the word 'banana'
#include <stdio.h>
/**THIS PROBLEM WAS TAKEN IN AN APPROACH SIMILAR TO LAB 6*/
int banana_finder(char arr[], int size, char banana[], int ba_size)
{
    int n = 0;// stepping through phrase
    int h = 0;// stepping through target phrase 'banana'
    int counter = 0;//For checking each character
    int find = 0;//If we find it or not

    //printf("Entered function %i is size and %i is ba_size\n", size, ba_size);//Check the size and banana size
    while(n < size)//The entire thing
    {
        //printf("We have %c as arr n and %c as banana %i is counter %i is the n\n",arr[n],banana[h], counter,n);//Give run down of checking and counters

        if(arr[n] != banana[h])//No match
        {
            if(counter != 0)//We were mid-way through match and need to reset things
            {
                find = counter;/** REMOVE THIS IF YOU DO NOT WANT THE GENERALIZED CASE*/
                h = 0;
                counter = 0;
            }
            else//Move to next character
            {
                n = n +1;
            }
        }
        else//There is a match
        {
            counter = counter+1;
            h = h+1;
            n = n+1;
            if(counter == (ba_size-1))//If we have enough counters to be considered a match
            {
                find = -1;
                n = size;
            }
        }
        if((n+ba_size > size + 1)&&counter == 0)//We get a make in time
        {
            n = size;
        }
    }

    return find;
}

int main()
{
    char array[1000];

    int ba_size = 7;
    char banana[] = {'b','a','n','a','n','a','\0'};
    int gate = 0;
    while(gate == 0)//Until the size of the input is at least banana
    {
        printf("Please enter a phrase:");//get the first character of the name
        char cur = getchar();
        int size = 0;
        //while they haven't hit enter get the next character
        while(cur != '\n')
        {
            array[size] = cur;
            cur = getchar();
            size = size+1;
        }
        //add the ‘\0’ character at the end of the useful info in the array
        array[size]='\0';
        if(size+1 < ba_size)
        {
            printf("The size of your string is too small. Please try again.\n\n");
        }
        else
        {
            gate = size+1;
        }
    }

    int determine = banana_finder(array, gate, banana, ba_size);

    if(determine == -1)
    {
        printf("The string '%s' WAS FOUND in your phrase!\n",banana);
    }
    else if(determine != 0)
    {
        int i;
        printf("The substring '");
        for(i = 0; i< determine; i++)
        {
            printf("%c",banana[i]);
        }
        printf("' was found in your phrase.\n", determine);
    }
    else
    {
        printf("The string %s was NOT found in your phrase.\n",banana);
    }
}
