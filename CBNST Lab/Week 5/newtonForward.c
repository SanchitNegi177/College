#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int factorial(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

int main()
{
    int n;
    printf("Enter order of matrix\n");
    scanf("%d", &n);
    float x[n], y[n][n];

    for (int i = 0; i < n; i++)
        scanf("%f", &x[i]);

    for (int i = 0; i < n; i++)
        scanf("%f", &y[0][i]);

    printf("Enter value of X to find\n");
    float findX;
    scanf("%f", &findX);

    for (int i = 1; i < n; i++) // table formation
    {
        for (int j = 0; j < n - i; j++)
        {
            y[i][j] = y[i - 1][j + 1] - y[i - 1][j];
        }
    }
    for (int i = 0; i < n; i++) // printing table
    {
        printf("y%d -> ", i);
        for (int j = 0; j < n - i; j++)
        {
            printf("%f ", y[i][j]);
        }
        printf("\n");
    }

    float a = x[0]; // finding value of u
    for (int i = 0; i < n; i++)
    {
        if (x[i] < findX)
            a = x[i];
    }

    float u = (findX - a) / (x[1] - x[0]); // x-a/h

    float ans = y[0][0]; // newton forward interpolation
    
    for (int i = 1; i < n; i++)
    {

        float uu = 1;
        for (int j = 0; j < i; j++)
        {
            uu *= (u - j);
        }
        ans += uu * y[i][0] / factorial(i);
    }
    printf("Solution of x = %f is : %f\n", findX, ans);
}