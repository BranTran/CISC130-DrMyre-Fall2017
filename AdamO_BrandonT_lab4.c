/*Adam O
Brandon T*/
#include <stdio.h>
#include <math.h>
int main ()
{
    /* These next lines of code, generate a
    ** random number between 0 and 2 (inclusive)
    ** and assign it to the variable “key”.
    ** This number is the key that the user
    ** is trying to guess.*/
//Moved the random number generator into loop
    /**Your code below here**/
    int user;//This is the what the user inputs
    int win;//This counts how many times the user has won
    int lose;//This counts how many times the user has lost
    int tie;//This counts how many times the user has tied
    int play;//This counts how many times the user has played
    int error;//This is an error counter in case there is an error
    float percent;//This calculates the win percentage
    char again;//This character is used to ask the user to play again

    win = 0;
    lose = 0;
    tie = 0;
    play = 0;
    error = 0;
    again = 'y';

    /*NUMBER 3a: Loop the entire process*/
    while((again == 'y') || (again == 'Y'))
    {
        /* Computer generated throw*/
        srand((unsigned)time(NULL));
        int comp_throw = rand()%3; // 0 = rock, 1 = paper, 2 = scissors

        error = 0;//Reset error counter so user can play again.

        /*NUMBER 1: Ask the user to enter 1, 2, or, 3*/
        printf("Please enter 1 for rock, 2 for paper, or 3 for scissors:");
        scanf(" %i", &user);

        /*NUMBER 1b: Error Checking*/
        if((user < 1)||(user > 3))
        {
            printf("ERROR Invalid Input: As a reminder, please type in 1, 2, or 3.\n\n");
            error = 1;
        }

        /*NUMBER 2: DO THE FIGHT*/
        /*We win*/
        else if((user == 1 && comp_throw == 2)||(user == 2 && comp_throw == 0)||(user == 3 && comp_throw == 1))
        {
            printf("You won!\n");
            win = win + 1;
            play = play + 1;


        }
        /*We lose*/
        else if((user == 1 && comp_throw == 1)||(user == 2 && comp_throw == 2)||(user == 3 && comp_throw == 0))
        {
            printf("You lose!\n");
            lose = lose + 1;
            play = play + 1;

        }
        /*We draw*/
        else if((user == 1 && comp_throw == 0)||(user == 2 && comp_throw == 1)||(user == 3 && comp_throw == 2))
        {
            printf("You tied!\n");
            tie = tie + 1;
            play = play + 1;
        }

        /*Bypass this line if error occurs*/
        if(error == 0)
        {
            /*NUMBER 3a: Ask to play again*/
            printf("Do you want to play again? (Y/N):");
            scanf(" %c", &again);
        }
    }

    /*NUMBER 3b: User does not want to play, now we give results*/
    printf("\n\nYou won %i times, lost %i times, and tied %i times \n", win, lose, tie );

    percent = (win*100.0)/play;
    printf("Your win record was %.2f%%\n",percent);


}
