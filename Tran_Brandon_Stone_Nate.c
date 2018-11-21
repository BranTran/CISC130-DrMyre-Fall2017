/** Brandon Tran and Nate Stone **/

#include <stdio.h>
#include <math.h>

/** Function 1: Positive Gate **/

int pos_num()
{
    int number;
    printf("Please enter a postive number: ");
    scanf(" %i", &number);

    //General Case
    if(number < 0)
    {
        printf("ERROR: The number must be positive.\n");
        int number = pos_num(number);
    }
    else
    {
        //Base Case
        return number;
    }

}//pos_num
/** Function 2: Fast Powers **/
int fast_pow(int base, int expo)
{
    int pow_num;//Final entry
    int half_pow;//Before a "doubling"
    //General Case
    if(expo != 1)
    {

        if(expo%2 == 1) // ODD do an extra multiplication (Can only be the first time through
        {
            expo = (expo-1)/2;
            half_pow = fast_pow(base, expo);
            pow_num = half_pow*half_pow*base;
        }
        else// EVEN Just to plug through
        {
            expo = expo/2;
            half_pow = fast_pow(base,expo);
            pow_num = half_pow*half_pow;
        }
    }
    else
    {
        //Base Case
        pow_num = base;
    }
    return pow_num;
}//fast_pow
/** Function 3: The Sequence **/
int jar_seq(int num)
{
    int n = num;
    if(n > 1) //general case
    {
        printf("%i, ", n);
        if (n%2 == 0)
        {
            n = n / 2;
            n = jar_seq(n);
        }
        else
        {
            n = (n * 3) + 1;
            n = jar_seq(n);
        }
    }
    else //base case
    {
        printf("%i\n", n);
        return n;
    }
}//jar_seq
/** Function 4: The Random **/
void fill_array(int array[], int a_size)
{

    //General Case
    if(a_size > 0)
    {
        fill_array(array,a_size-1);

//        int result = rand()%314; // Take in numbers 0 to 313
        int result = rand()%10; // Take in numbers 0 to 313
//        int rand_num = result + 7; // Shift values to 7 to 330 inclusively
        int rand_num = result;
        int i = a_size - 1;
        array[i] = rand_num;
    }
    else
    {
    srand((unsigned)time(NULL));//Base Case // srand seeds the random numbers. Only need to seed once
    }
}
/** Function 5: The Print DONE RIGHT **/
void print_array(int array[], int a_size)
{
    if(a_size > 1)
    {
        print_array(array, a_size - 1);
        printf(", %i", array[a_size - 1]);

    }
    else
    {
        printf("%i", array[0]);
    }
}

/** OLD Function 6: The Flip // Moving in memory is dangerous, but worth a try. I'm keeping it here because why not
void flip_array(int Aray[], int Bray[], int a_size)
{
    int i = 0;
    //Base Case
    if(a_size == 0)
    {
        //Do nothing
    }
    //General Case
    else
    {
        Bray[a_size-1] = Aray[i];
        flip_array(Aray+1,Bray,a_size-1);
    }

    Aray-1; // bring the array pointer back to right place in memory
}**/

/** Function 6: The Flip **/ //I'll just shamelessly add in an extra variable since the lab does not strictly restrict input (It only asks for input of two arrays of the same size)
void flip_array(int Aray[], int Bray[], int start, int zero)
{
    //Base Case
    if(start == 0)
    {
        //Do nothing
    }
    //General Case
    else
    {
        Bray[zero] = Aray[start-1];
        flip_array(Aray,Bray,start-1, zero+1);
    }
}

/** Function 7: Duplicity **/
int identical(int x, int array[], int a_size)
{
    int times;
    //General Case
    if(a_size > 1)
    {
        times = identical(x,array,a_size-1);
        if(array[a_size-1] == x)
        {
                times = times + 1;
        }
    }
    else // Base Case
    {
        if(array[a_size-1] == x) // Checks if the first number matches
        {
                times = 1;
        }
        else
        {
            times = 0;
        }
    }
    return times;
}
/** Function 8: The Main **/
int main()
{
    //Function 2 feat. 1
    printf("FAST POWERING:\n");
    printf("Select a base\n");
    int base = pos_num();
    printf("Select an exponent\n");
    int expo = pos_num();

    printf("%i^%i = %i\n", base, expo, fast_pow(base,expo));

    //Function 3 feat. 1
    printf("\nJARVIS SEQUENCE:\n");
    printf("Select a start number\n");
    int num = pos_num();
    printf("The Jarvis Sequence for %i is:\n", num);
    jar_seq(num);

    //Function 4 feat 1 & 5
    printf("\nRANDOM ARRAY:\n");
    printf("Select an array size\n");
    int size = pos_num();
    int array[size];
    fill_array(array,size);
    print_array(array,size);

    //Function 6 feat 4
    printf("\n\nBACKWARDS ARRAY:\n");
    printf("Here is your array backward:\n");
    int flip[size];
    //flip_array(array,flip,size); What I wanted but could not achieve
    flip_array(array,flip,size,0);
    print_array(flip,size);

    //Function 7 feat 1
    printf("\n\nHOW MANY TIMES IS IT IN THE ARRAY:\n");
    printf("Select a number to search for\n");
    int target = pos_num();
    int times = identical(target,array,size);
    printf("%i was there %i times\n",target,times);
}
