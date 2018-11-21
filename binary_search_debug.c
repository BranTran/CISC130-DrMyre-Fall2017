/**
 * C Program to Perform Binary Search using Recursion
 **/
#include <stdio.h>

/** Some vaguely easy to understand sort **/
void bubble_sort(int list[], int size)
{
    int temp, i, j;
    for (i = 0; i < size; i = i+1)
    {
        for (j = i; j < size; j = j+1)
        {
            if (list[i] > list[j])
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

/**
* Finds the index of key.
* Takes the array, index bounds (lo and high), and the key
*   as input.
* Returns index if found, -1 if not.
**/
int binary_search(int list[], int lo, int hi, int key)
{
    int mid; // middle index
    mid = ((hi - lo) / 2) + lo; // add move mid steps from the lo
    printf("%i %i %i\n", lo, mid, hi); //Test period
    if(list[mid] == key)//If we find the thing
    {
        /** Base case **/
    }


    else  if(lo > hi)// base case
    {
        // Key not found
        mid = -1;
    }    /** General Case**/
    else if(list[mid] > key) // the key is earlier in the array (0 to mid)
    {
        mid = binary_search(list, lo, mid-1, key);
    }
    else if(list[mid] < key)// the key is later in the array (mid to hi)
    {
        mid = binary_search(list, mid+1, hi, key);
    }

    return mid;
}
/** Function 4: The Random **/
void fill_array(int array[], int a_size)
{

    //General Case
    if(a_size > 0)
    {
        fill_array(array,a_size-1);

        int result = rand()%314; // Take in numbers 0 to 313
        int rand_num = result + 7; // Shift values to 7 to 330 inclusively
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

int main()
{
    int key, size, i;

    printf("Enter size of a list: ");
    scanf(" %d", &size);//Getting a size

    int list[size];//Making an array with trash inside (Nothing declared)
    fill_array(list,size);
    print_array(list,size);
    printf("\n");
    /** Sort the list **/
    bubble_sort(list, size);
    print_array(list,size);

    printf("\n\n");
    printf("Enter key to search\n");
    scanf(" %d", &key);//What we are looking for

    int loc = binary_search(list, 0, size, key);

    if(-1 == loc){
        printf("Key not found\n");
    }
    else{
        printf("Found %d at list[%d]", key, loc);
    }

    return 0;
}
