/** Claire Rubio and Brandon Tran **/
#include <stdio.h>
#include <string.h>
int main()
{
    int num_people = 10;   // initiates variables for storing data about students and DNA
    int dna_length = 1000;
    int num_seqs;
    char dna[num_people][dna_length];
    FILE* fp = fopen("dna.txt", "r");
    int i = 0;
    while(fgets(dna[i], dna_length, fp) != NULL)
    {
        i = i + 1;
    }
    /**Ask for input to get each persons name
    * and the DNA sequences of interest for each person
    */
    char people[num_people][100];
    int row = 0;
    //one name per row and go until we have the number people
    while(row < num_people)
    {
        // Get the name of person i
        printf("Please enter the name of person %i: ",row+1);
        //get the first character of the name
        char cur = getchar();
        int col = 0;
        //while they haven't hit enter get the next character
        while(cur != '\n')
        {
            people[row][col] = cur;
            cur = getchar();
            col = col +1;
        }
        //add the ‘\0’ character at the end of the useful info in the array
        people[row][col]='\0';

        row = row + 1;
    }
    printf("How many genetic sequences are you interested in? ");
    scanf(" %i", &num_seqs);
    fflush(stdin);

    /** YOUR WORK GOES BELOW HERE **/
    //Ask for the dna sequences in question and stores by row each string sequence in array dnaseqs
    int Q;  // use Q to step through rows of dnaseqs array
    Q = 0;
    char dnaseqs[num_seqs][1000];  // array to store DNA sequence(s) of interest

    while(Q < num_seqs)
    {
        // Get the first sequence of interest
        printf("Please enter the DNA sequence of interest %i: ",Q+1);
        //get the first character of the DNA sequence
        char cur = getchar();
        int col = 0;
        //while they haven't hit enter get the next character of the DNA sequence
        while(cur != '\n')
        {
                dnaseqs[Q][col] = cur;
                cur = getchar();
                col = col +1;
        }
        //add the ‘\0’ character at the end of the useful info in the array
            dnaseqs[Q][col]='\0';
            Q = Q + 1;
    }

    //Get the name of the behavior trait
    int P;
    P = 0;
    char predis[num_seqs][1000];  // array to store in each row of predis a different trait of interest

    while(P < num_seqs)
    {
        // Get the first trait of interest
        printf("What is the behavior trait associated with genetic sequence %i: ",P+1);
        //get the first character of the trait
        char cur = getchar();
        int col = 0;
        //while they haven't hit enter get the next character trait
        while(cur != '\n')
        {
            predis[P][col] = cur;
            cur = getchar();
            col = col +1;
        }
        //add the ‘\0’ character at the end of the useful info in the array
        predis[P][col]='\0';
        P = P + 1;
    }
    /** This section checks to see if the dna sequences of interest  **/

    int row_interest;
    int char_interest;
    int I;
    int J;
    int hurray; //Counting when things go right
    int clean;
    int illness[num_people][num_seqs];

    //Go through each person's DNA given
    for(I=0; I<num_people; I=I+1)
    {
        //Go through each sequence of interest
        for(row_interest = 0; row_interest < num_seqs; row_interest = row_interest + 1)
        {
            //Reset clean counter, check counter, restart 'scan' to beginning of DNA given and DNA interest
            char_interest = 0;
            J = 0;
            clean = 0;
            hurray = 0;
            //Go through each character of the DNA sequence of interest
            while (char_interest < strlen(dnaseqs[row_interest]))
            {
                //Go through if char_interest does not match with DNA J
                if(dnaseqs[row_interest][char_interest] != dna[I][J])
                {
                    if (hurray != 0)//RESET if we fail to get through the entire sequence of interest
                    {
                        char_interest = 0;
                        hurray = 0;
                    }
                    else
                    {
                        J = J + 1;
                    }
                }
                else//if it does match
                {
                    char_interest = char_interest + 1;
                    hurray = 1;
                    J = J + 1; //check next thing after success
                }

                if ((J+strlen(dnaseqs[row_interest])) > strlen(dna[I]))//If we have more Sequence to check than DNA given
                {
                    char_interest = strlen(dnaseqs[row_interest])+1;//Get out of the loop
                    clean = 1;
                }
            }//while char_interest

            if (clean == 1)//made it through without illness
            {
                illness[I][row_interest] = 0;
            }
            else//This person does have this illness
            {
                illness[I][row_interest] = 1;
            }
        }//for row_interest which is the illnesses
    }//for I which is the people

    int person;
    int disease;
    int sick = 0;

    for(person=0; person<num_people; person=person+1)//Each Person
    {
        printf("%s is predisposed to:", people[person]);

        for(disease=0; disease<num_seqs; disease=disease+1)
        {
            if (illness[person][disease] == 1)
            {
                printf("\n\t\t%s", predis[disease]);
                sick = sick + 1;
            }
            else if ((disease == (num_seqs-1))&&(sick == 0))
            {
                printf("\n\t\tnothing");
            }
        }
        printf("\n\n");
        sick = 0;
    }
}//int main
