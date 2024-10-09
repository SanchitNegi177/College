#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

float check(double x)
{
    return x * x * x - x - 1;
    // return x*log10(x)-1.2;
}

void printBisectionMethod(float x, float y, float error)
{
    float prev = -1;
    for (int i = 1;; i++)
    {
        float mid = (x + y) / 2;
        float fx = check(mid);
        if(fabs(fx) == 0) 
        {
            printf("Exact root = %f\n", mid);
            break;
        } 
        else if (fx < 0)
            x = mid;
        else
            y = mid;

        printf("%d Iteration, value of x is %f,value of (%f) is %f \n", i, mid, mid, fx);

        if (fabs(fabs(prev)- fabs(mid)) <= error && prev!=-1)
        {
            printf("Root of the equation is %f after %d itertaion\n", mid, i);
            break;
        }
        prev = mid;
    }
}

int main()
{
    float x, y;
    while (true)
    {
        printf("Enter interval x and y\n");
        scanf("%f %f", &x, &y);
        if (check(x) < 0 && check(y) > 0)
        {
            printf("The roots lies in between %f and %f\n", x, y);
            break;
        }
        printf("The roots does not lies in between %f and %f\n", x, y);
    }

    printf("Enter allowed error\n");
    float error;
    scanf("%f", &error);

    printBisectionMethod(x, y, error);

    return 0;
}