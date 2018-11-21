#include <stdio.h>
    /*This program swaps lowercase letters with their
    uppercase counterpart and vice versa*/

int main()
{
    char string[100];
    int step = 0;
    //Ask for a string
    printf("Write down a string:");
    scanf(" %s", &string); // Scanf makes it impossible to read in spaces

    while(string[step] != '\0')
    {
        //Lowercase letters
        if ((string[step] >= 'a')&&(string[step] <= 'z'))
        {
            string[step] = string[step] - 32;
        }
        //Uppercase letters
        else if ((string[step] >= 'A')&&(string[step] <= 'Z'))
        {
            string[step] = string[step] + 32;
        }
        //Keep everything else the same
        else
        {
            string[step] = string[step];
        }
        step = step + 1;
    }
    //print the string
    printf("The string length is %i\n", strlen(string));
    printf("%s\n",string);
}
