#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

float f(float x)    // 
{
    return x * x * x - 5*x + 1;
    // return x*x*exp(-x/2.0)-1;
}

void secantMethod(float x0, float x1, float error)
{
    float prev = -1;
    for (int i = 1;; i++)
    {
        if(f(x0)==f(x1))
        {
            printf("Secant Method Failed!\n");
            break;
        }

        float root = x1-((x1-x0)/(f(x1)-f(x0)))*f(x1);
        
        x0=x1;
        x1=root;

        printf("%d Iteration, value of x is %f \n", i, root);

        if (fabs(fabs(prev) - fabs(root)) <= error && prev != -1)
        {
            printf("Root of the equation is %f after %d itertaion\n", root, i);
            break;
        }
        prev = root;
    }
}

int main()
{
    float x0, x1;
    printf("Enter interval x0 and x1\n");
    scanf("%f %f", &x0, &x1);

    printf("Enter allowed error\n");
    float error;
    scanf("%f", &error);

    secantMethod(x0, x1, error);

    return 0;
}