/**The Dream Team NOTE: Internet Explore cannot be open after sending email, or Code Blocks gets angry and refuses to save
Brandon Tran
Jose Rocha
Reid Sobania
*/
#include <stdio.h>
#include <math.h>

/**
 * Helper functions here
 **/
float min(float data_array[], int size_array)
{
    float minimum = data_array[0];
    int i;

    for(i=0; i<size_array; i = i+1)
    {
        if(data_array[i] < minimum)
        {
            minimum = data_array[i];
        }
    }

    return minimum;
}

float max(float data_array[], int size_array)
{
    float maximum = data_array[0];
    int i;

    for(i=0; i<size_array; i = i+1)
    {
        if(data_array[i] > maximum)
        {
            maximum = data_array[i];
        }
    }

    return maximum;

}

float mean(float data_array[], int size_array)
{
    float sum = 0.0;
    float average;
    int i;

    for(i=0;i<size_array;i=i+1)
    {
        sum = sum + data_array[i];
    }

    average = (sum/size_array);

    return average;
}

float variance(float data_array[], int size_array)
{
    int i;
    float variance=0.0;
    for(i=0;i<size_array;i=i+1)
    {
        variance = variance + (pow((data_array[i] - mean(data_array,size_array)),2));
    }
    variance = variance / (size_array-1);
    return variance;
}

float stdev(float data_array[], int size_array)
{
    float stand;
    stand = sqrt(variance(data_array,size_array));
    return stand;
}

/**
 * Here is where the program starts
 **/
int main()
{
	int n_samples = 15;
    float ph[15] = {6.3,7.0,7.3,7.4,7.3,7.5,6.1,6.7,6.8,6.6,6.6,6.6,7.0,6.9,7.1};

//printf("The minimum ph is %.1f\nThe maximum ph is %.1f\nThe average ph is %.1f\nThe variance of ph is %.3f\nThe stdev of ph is %.3f\n", min(ph,n_samples), max(ph,n_samples), mean(ph,n_samples), variance(ph,n_samples), stdev(ph,n_samples));
    /*printf("The minimum ph is %.1f\n",min(ph,n_samples));
    printf("The maximum ph is %.1f\n",max(ph,n_samples));
    printf("The average ph is %.1f\n",mean(ph,n_samples));
    printf("The variance of ph is %.3f\n",variance(ph,n_samples));
    printf("The stdev of ph is %.3f\n",stdev(ph,n_samples));

    */

    /** the professor would like our format to be printed as follows*/
        printf("min\tmax\tmean\tvar\tstdev\n");
        printf("%.1f\t%.1f\t%.2f\t%.3f\t%.3f\n",min(ph,n_samples), max(ph,n_samples), mean(ph,n_samples), variance(ph,n_samples), stdev(ph,n_samples));
    int p = 5;
    int p = 3;


    return 0;
}
