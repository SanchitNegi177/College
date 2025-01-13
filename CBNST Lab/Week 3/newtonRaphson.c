#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

float f(float x)
{
    // return 3 * x  - cos(x) - 1;
    return x-sqrt(12);
}

float diff(float x)
{
    // return 3+sin(x);
    return 1;
}

float checkInterval(float x)
{
    // return 3 * x  - cos(x) - 1;
    return x-sqrt(12);
}

void newtonMethod(float x0, float error)
{
    float prev = -1;
    for (int i = 1;; i++)
    {
        if(diff(x0)==0)
        {
            printf("Newton Raphson Method Failed!\n");
            break;
        }

        float root = x0-(f(x0)/diff(x0));
        
        x0=root;

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
    float x, y;
    while (true)
    {
        printf("Enter interval x and y\n");
        scanf("%f %f", &x, &y);
        if(checkInterval(x)==0 )
        // {
        //     printf("Exact roots is %f\n", x);
        //     break;
        // }
        // if( checkInterval(y)==0)
        // {
        //     printf("Exact roots is %f\n", y);
        //     break;
        // }
        
        if (checkInterval(x) < 0 && checkInterval(y) > 0)
        {
            printf("The roots lies in between %f and %f\n", x, y);
            break;
        }
        printf("The roots does not lies in between %f and %f\n", x, y);
    }

    printf("Enter allowed error\n");
    float error;
    scanf("%f", &error);

    newtonMethod((y+x)/2, error);

    return 0;
}