#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
// x^3-4x-9

// x=(4x+9)^1/3
// differentiation 4/3 (4x+9)^-2/3
bool checkValid(float x)
{
    // return abs((4.0 / 3) * pow((4 * x + 9), (-2.0 / 3))) < 1; // differentiation
    // return fabs(3*x*x/4)<1;
    return fabs(sin(x)+(x-1)*cos(x))<1;

}
float checkInterval(float x)    // check range [a,b] f(x)
{
    // return x * x * x - 4 * x - 9;
    return sin(x)*(x+1)-(x-1);
}
float calculate(float x)
{
    // return pow((4 * x + 9), (1.0 / 3));     // phie(x)
    // return (x*x*x-9)/4;
    return sin(x)*(x-1)-1;
}

void printIterationMethod(float x, float y, float error)
{
    float prev = -1;
    float mid = 1e9;
    while (true)
    {
        // printf("Enter value in between %f and %f\n", x, y);
        printf("Enter value of x");
        scanf("%f", &mid);
        if(checkValid(mid))
        {
            break;
        }
        // printf("Enter another value in between %f and %f\n", x, y);
    }

    for (int i = 1;; i++)
    {
        float fx = calculate(mid);
        mid = fx;

        printf("%d Iteration, value of x is %f,value of (%f) is %f \n", i, mid, mid, fx);

        if (fabs(fabs(prev) - fabs(mid)) <= error && prev != -1)
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
    // while (true)
    // {
    //     printf("Enter interval x and y\n");
    //     scanf("%f %f", &x, &y);
    //     if (checkInterval(x) < 0 && checkInterval(y) > 0)
    //     {
    //         printf("The roots lies in between %f and %f\n", x, y);
    //         break;
    //     }
    //     printf("The roots does not lies in between %f and %f\n", x, y);
    // }

    printf("Enter allowed error\n");
    float error;
    scanf("%f", &error);

    printIterationMethod(x, y, error);

    return 0;
}