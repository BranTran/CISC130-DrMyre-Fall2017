#include <stdio.h>

int main()
{
    float grade;
    grade = 0.0;
    while (grade < 90 || grade>100)
    {
        //Ask for a whole number numerical grade to update
        printf("Please report your grade:");
        scanf(" %f", &grade);
        //Report a letter grade with comments made in pure fun
        /*Catch errors
            -Go Over 100
            -Less than 0
        */
        //>100
        if(grade>100)
        {
            printf("This class does not have extra credit.\nThis grade has been verified as impossible.\nThe Dean of Students will be notified about possible grade tampering.\n");
        }
        //100>= >=90 is A
        else if(grade>=90)
        {
            printf("Your grade is an A. Well done\nDon't forget to invest\n");
        }
        //>=80 is B
        else if(grade>=80)
        {
            printf("Your grade is a B. Good work.\nI think investing would be beneficial to you.\n");
        }
        //>=70 is C
        else if(grade>=70)
        {
            printf("Your grade is a C. This is passable.\nRemember to invest so you can start recouping your losses from loans.\n");
        }
        //>=60 is D
        else if(grade>= 60)
        {
            printf("Your grade is a D, maybe you should invest your time in different things, like investing.\n");
        }
        //<0
        else if(grade<0)
        {
            printf("You have gained too many demerit points. If there was a F-, it would be above your grade.\n");
        }
        else
        {
            printf("Your grade is an F, you will need to retake for a higher grade to receive credit.\nPerhaps your time would be better spent investing.\n");
        }//else
    }//while
}//int main
