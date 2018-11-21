#include <stdio.h>

int main()
{
    int my_int;
    int ignore;

    printf("What is your age: \n");
    scanf(" %i", &my_int);

    printf("What is your age again? I wasn't paying attention: \n");
    scanf(" %i", &ignore);

    if(my_int != ignore)
    {
        printf("Kid tried to change his answer!\n\nHmpf, a kid thinks he's funny, huh?\n\nI've got five words for you buddy.\n\n\n");
        my_int = 0;
    }


    if(21 > my_int)
    {
        printf("Go to SCHOOL! and invest\n");
    }
    else if( 21 <= my_int && 36 > my_int)
    {
        printf("GET A JOB!!! also invest\n");
    }
    else if (36 == my_int)
    {
        printf("You MUST get married and also invest.\n");
    }
    else if (36 < my_int && 105 > my_int)
    {
        printf("Play golf, after you retire and invest.\n");
    }
    else
    {
        printf("Play Bingo, if you Dare. don't forget to invest\n");
    }

}
