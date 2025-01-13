
#include <stdio.h>
#include <math.h>

int factorial(int x)
{
    int fact = 1;
    for (int i = 1; i <= x; i++)
    {
        fact *= i;
    }
    return fact;
}

float u_cal(float u, int n)
{
    float temp = u;
    int val = 1;
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 1)
        {
            temp = temp * (u - val);
        }
        else
        {
            temp = temp * (u + val);
            val++;
        }
    }
    return temp;
}
int main()
{
    int n;
    printf("Enter No. of Observations: ");
    scanf("%d", &n);
    float x[n], y[n][n];
    float x1;
    printf("Enter the value: ");
    scanf("%f", &x1);
    printf("Enter the Values of x and y\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i][0]);
    }

    // calculate forward difference table
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }
    printf("\nForward Difference Table:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f", x[i]);
        for (int j = 0; j < n - i; j++)
        {
            printf("  %f", y[i][j]);
        }
        printf("\n");
    }
    float sum = y[n / 2-1][0];
    float h = (x[1] - x[0]);
    float u = (x1 - x[n / 2-1]) / h;

    for (int i = 1; i < n; i++)
    {
        sum += (u_cal(u, i) * y[(n - i) / 2][i]) / factorial(i);
    }

    printf("\nThe Interpolated value at x=%0.4f is %0.4f\n", x1, sum);

    return 0;
}
