#include <stdio.h>

int main()
{
    //Ask for a whole number numerical grade
    float grade;
    printf("Please report your grade:");
    scanf(" %f", &grade);

    //Report a letter grade with comments
    if(grade>100)
    {
        printf("This class does not have extra credit.\nThis grade has been verified as impossible.\nThe Dean of Students will be notified about possible grade tampering.\n");
    }
    else if(grade>=90)
    {
        printf("Your grade is an A. Well done\nDon't forget to invest\n");
    }
    else if(grade>=80)
    {
        printf("Your grade is an B. Good work.\n");
    }
    else if(grade>=70)
    {
        printf("Your grade is an C. This is passable.\nRemember to invest so you can recoup start recouping your loans.\n");
    }
    else if(grade>= 60)
    {
        printf("Your grade is an D, maybe you should invest your time in different things, like investing.\n");
    }
    else
    {
        printf("Your grade is an F, you will need to retake for a higher grade to receive credit.\nPerhaps your time would be better spent investing instead.\n");
    }
}
