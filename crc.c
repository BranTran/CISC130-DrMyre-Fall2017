#include <stdio.h>
#include <math.h>

int main()
{

    /**
    * Part A.
    *
    * CRC fears that their Handbook of Chemistry and Physics has
    * become too advanced and is scaring away new readers.
    * CRC has requested our help to assist in the creation of a
    * new CRC Handbook of multiplication tables.
    *
    * CRC has asked for a program that does the following:
    *




    *    Example for inputs of 1 and 2:
    *    Mult:
    *    i\j  1
    *    1    1
    *    2    2
    *
    **/

    /** Step 1
    * 1) Ask for the integer for which you will calculate multiples. **/
    int integer;
    printf("What integer do you wish to multiply?");
    scanf(" %i", &integer);


    /** Step 2
     * 2) Ask how many multiples are required.**/
    int multiples;
    printf("How many multiples are required?");
    scanf(" %i", &multiples);


    /** Step 3
    * 3) Use loops to generate (pt2) multiples of (pt1) and store
    *      the results in a 2D array (a table/matrix).**/
    int multiarray[integer+1][multiples+1];
    int i;
    int j;
    for(i = 0; i <= integer; i++)
    {
        if(i == 0)//To get the header above
        {
            multiarray[0][0] = 0;
            for(j=1; j <= multiples; j++)
            {
                multiarray[0][j] = j;
            }
        }
        else
        {
            multiarray[i][0] = i;//To get the header on the left
            for(j=1; j <= multiples; j++)
            {
                multiarray[i][j]=i*j;
            }
        }
    }


    /** Step 4
     * 4) Print the multiplication table.**/
    for(i=0; i <= integer; i++)
    {
        for(j=0; j <= multiples; j++)
        {
            printf("%i\t",multiarray[i][j]);
        }
        printf("\n");
    }


    /**
    * Part B
    *
    * Volume 2 of the new CRC Handbook will include tables of
    * logarithms.
    *
    * CRC has requested a program that does the following:
    *
    * 1) Ask for the largest integer used for finding logarithms.
    * 2) Ask for the largest base that will be used.
    * 3) Use loops to calculate all of the logarithms to fill
    *       a 2D array (a table/matrix) that stores the results.
    *       Remember that log_1(x) is undefined.
    * 4) Print the table to the screen to 3 digits of precision.
    *    For example, an input of 2 and 4 will display:
    *    log_b(i)
    *    i\b     2       3       4       5
    *    1       0.000   0.000   0.000   0.000
    *    2       1.000   0.630   0.500   0.430
    **/

    /** Step 1 **/
    int large;
    printf("What is the largest integer used?");
    scanf(" %i", &large);

    /** Step 2 **/
    int base;
    printf("What is the largest base used?");
    scanf(" %i", &base);

    /** Step 3 **/
    float logarray[large+1][base];
    int p;
    int q;
    for(p = 0; p <= large; p++)
    {
        if(p == 0)//To get the header above
        {
            logarray[0][0] = 0;
            for(q=1; q <= base; q++)
            {
                logarray[0][q] = q+1;
            }
        }
        else
        {
            logarray[p][0] = p;//To get the header on the left
            for(q=1; q <= base; q++)
            {
                logarray[p][q]=1.0*(log(p)/log(q+1));
            }
        }
    }
    /** Step 4 **/
    for(p=0; p <= large; p++)
    {
       /* if(p == 0)//To get the header above
        {
            for(q=0; q < base; q++)
            {
                printf("%.0f\t",logarray[0][p]);
            }
        }*/
        //else
       // {
         //   printf("%.0f\t",logarray[q][0]);
            for(q=0; q < base; q++)
            {
                printf("%.3f\t",logarray[p][q]);
            }
        //}
        printf("\n");
    }
    return 0;
}
