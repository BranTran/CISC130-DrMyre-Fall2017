#include <stdio.h>


/**
* This fills an integer array with each element = its index +1
**/
void fill_array(int arr[], int size)
{
    int i;
    i = 0;
    while(i < size){
        arr[i] = i+1; /**ISSUE start at arr[i] = arr[0], and put it i+1 = 1*/
        i = i + 1;
    }
}

/**
* Prints the primes in our sieve
**/
void print_primes(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i = i + 1){/**ISSUE i is strictly less than (<) size instead of <=*/
        if(arr[i] != -1){
            printf("%d\t", arr[i]);/**ISSUE use tabs instead of space for neat output*/
        }
    }
}


/**
* Removes multiples of arr[start_idx] in arr
* by setting them to -1
**/
void remove_multiples(int arr[], int size, int start_idx)
{
    int cur_num = arr[start_idx];

    int i;
    i = start_idx+cur_num; // offsets to the next multiple of cur_num
    while(i < size)
    {
        arr[i] = -1;  // sets the next multiple to -1
        i = i + cur_num;/** Increment the index //ISSUE increment on the prime number, not one*/
    }

}

/**
* Runs Erastosthenes sieve to find prime numbers
* Always starting with 2, because we know 1 is "prime",
* and removing multiples of 1 wipes out the sieve
**/
void e_sieve(int arr[], int size)
{
    int i;
    i = 1;/**ISSUE i = 1, since start getting rid of primes at 2 (i.e. arr[1])*/
    while(i < size/2){
        int cur_num = arr[i];

        if(cur_num != -1)
        {
            /**
            * If the number at the current index is
            * not -1, we have to remove all of its
            * multiples
            **/
            remove_multiples(arr, size, i);
        }

        i = i + 1;
    }
}

int main(){
    /** Create an array of numbers
        1) Set the limit/size for our array
        2) Declare the array
        3) Fill our array with numbers
    **/
    int limit = 1000;

    int sieve[limit];

    fill_array(sieve, limit);

    /**
    * Apply the Sieve
    **/
    e_sieve(sieve, limit);


    /** Print the primes **/
    printf("Primes to %i:\n", limit);
    print_primes(sieve, limit);

}
