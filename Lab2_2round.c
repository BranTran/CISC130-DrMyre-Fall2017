#include <stdio.h>
#include <math.h>

int main()
{
    float bill = 52.43;

    float tip = bill*.1;

    float round = tip*100+0.5;

    int rounded = round;

    float finalround = rounded/100.;

    printf("We get: %.2f, %f, %f, %i, %f", bill, tip, round, rounded, finalround);
}
