/*
Front Page
Questions Page
Lab Perfoma


Aim/Objective: To deduce an error in a given problems         // Hand-written
Algo:
Code:

Output:

We will find :
Absolute Error= abs(True value - Approximate Value)
Relative Error= Absolute Error / True value = abs(True value - Approximate Value) / True value
Percentage Error= Relative Error * 100 = abs(True value - Approximate Value)*100 / True value


Best approximation

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n;
    printf("Enter number of entries\n");
    scanf("%d", &n);

    float approxValue[n];
    float absoluteError[n];
    float trueValue;
    printf("Enter true value\n");
    scanf("%f", &trueValue);

    for (int i = 0; i < n; i++)
    {
        printf("Enter %d approx value\n", i + 1);
        scanf("%f", &approxValue[i]);
    }

    float bestApprox, leastError = 1e9;
    for (int i = 0; i < n; i++)
    {
        absoluteError[i] = fabs(trueValue - approxValue[i]);
        if (leastError > absoluteError[i])
        {
            leastError = absoluteError[i];
            bestApprox = approxValue[i];
        }
    }

    printf("Best Approximation is %f\n", bestApprox);
    printf("With least Absolute Error of %f\n", leastError);

    return 0;
}
