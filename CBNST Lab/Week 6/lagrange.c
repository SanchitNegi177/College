
#include <stdio.h>
float lagrangeInterpolation(float x[], float y[], int n, float x1)
{
    float result = 0;
    for (int i = 0; i < n; i++)
    {
        float term = y[i];
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                term = term * (x1 - x[j]) / (x[i] - x[j]);
        }
        result += term;
    }
    return result;
}
int main()
{
    int n;
    printf("Enter number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];
    float x1;

    printf("Enter the values of x and y:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
    }

    // Input x1, the value to interpolate
    printf("Enter the value of x to interpolate: ");
    scanf("%f", &x1);

    float y1 = lagrangeInterpolation(x, y, n, x1);

    printf("For x = %f, interpolated y = %0.4f\n", x1, y1);

    return 0;
}
