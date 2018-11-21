//Number 5 in Review
//Recursive function to count number of vowels in a string
#include <stdio.h>

/**THIS FUNCTION DOES NOT CONSIDER THE LETTER Y A FUNCTION AT ALL*/
int vowel_count(char array[], int size)
{
    int vowel;
    char letter;
    if(size == 0)//
    {
        vowel = 0;//Begin vowels at 0
    }
    else
    {
        vowel = vowel_count(array,size-1);//Recurse from size to 1
        letter = array[size-1];//Get letters size-1 to 0 of array
        if((letter == 'a')||(letter == 'e')||(letter == 'i')||(letter == 'o')||(letter == 'u')||
           (letter == 'A')||(letter == 'E')||(letter == 'I')||(letter == 'O')||(letter == 'U'))
        {
            vowel = vowel + 1;
        }
    }
    return vowel;
}

int main()
{
    char array[100];
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

    int vowels = vowel_count(array, size+1);
    printf("You have %i vowels in your phrase.\n",vowels);
}
