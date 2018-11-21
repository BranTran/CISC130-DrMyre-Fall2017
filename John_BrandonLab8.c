/** Brandon Tran
    John MacLaughlin **/
#include <stdio.h>
/**Pass in multiple swears*/
int continue_reader(char curses[][1001], int counter)
{
    int trigger;
    printf("Enter a word to censor, or enter to continue: ");
    gets(curses[counter]);

    if(curses[counter][1] != '\0')
    {
        //printf("Counter is %i", counter);
        trigger = counter + 1;
    }
    else
    {
        //printf("Broke free of loop \n");
        trigger = 0;
    }
    //printf("The trigger is %i", trigger);
    return trigger;
}
int censor(char phrase[], int psize, char curses[], int csize)
{
    int n;
    int i;
    int foul = 0;
    i = 0;
    while(phrase[i] != '\0')
    {
        /** If the first letter matches **/
        if(phrase[i] == curses[0])
        {
            int j;
            j = 0;
            int match;
            match = 1; // match is true
            while(curses[j] != '\0' && match == 1)//Go through each letter, or until false
            {
                if(curses[j] != phrase[i+j])
                {
                    match = 0; // match is false
                }
                j = j+1;
            }
            if(curses[j] == '\0')//End reached, execute censor
            {
                if((phrase[i+j] == ' ') || (phrase[i+j] == '\0')) //if it is indeed the word
                {
                    foul = 1;
                    int k;
                    k = 0;
                    n = j;
                    while(k < n) // replace with stars
                    {
                        phrase[i+k] = '*';
                        k = k + 1;
                    }
                }
            }
        }

        /** Skip to the next word **/
        while(phrase[i] != ' ' && phrase[i] != '\0')
        {
            i = i + 1;
        }
        if(phrase[i] != '\0')
        {
            i = i+1;
        }
    }
    return foul;
}
int main()
{
    /** Sets curse word */
    int csize = 1001;
    char curses[1000][csize];
    int trigger = 1;
    int counter = 0;

    while(trigger != 0) //Until the trigger is turned off
    {
        trigger = continue_reader(curses[counter],counter);
        counter = counter + 1; // Move to next element in array
    }

    /** Set up storing array **/
    int strsize = 1001;
    char str[strsize];


    /** Read in the phrase **/
    printf("Please enter a phrase:\n");
    gets(str);


    /** Do the thing **/
    int i = 0;
    int foul = 0;
    while(i <= counter)
    {
        foul = foul + censor(str, strsize, curses[i], csize);
        i = i + 1;
    }

    if(foul == 1)
    {
        printf("\nThere was potty language in your phrase. It was censored. See below:\n");
    }
    else
    {
        printf("\nYour sentence was clean. Here is what you entered:\n");
    }
    printf("%s\n", str);
    return 0;
}
