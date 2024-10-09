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

*/
/*
    Name: Sanchit Negi
    Section: A1
    Univ Roll No: 2219549
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float trueValue, approxValue;
    printf("Enter True value\n");
    scanf("%f", &trueValue);
    printf("Enter Approximate value\n");
    scanf("%f", &approxValue);

    float absoluteError = fabs(trueValue - approxValue);
    float relativeError = absoluteError / trueValue;
    float percentageError = relativeError * 100;

    printf("Absolute Error is %f\n", absoluteError);
    printf("Relative Error is %f\n", relativeError);
    printf("Percentage Error is %f\n", percentageError);

    return 0;
}
