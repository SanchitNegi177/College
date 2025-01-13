
#include <stdio.h>
int main()
{
    int n, i;
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    double a, b;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    double x[n], y[n];
    
    printf("Enter the values of x and y:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d]: ", i + 1);
        scanf("%lf", &x[i]);
        printf("y[%d]: ", i + 1);
        scanf("%lf", &y[i]);
    }

    for (i = 0; i < n; i++)
    {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    //  sumY = n*a + b * sumX       .... a = (sumY-b*sumX) / n
    //  sumXY = a*sumX + b * sumX2  .... b = (sumXY- a *sumX) / sumX2

    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = (sumY - b * sumX) / n;

    printf("\nThe linear equation that fits the given data is:\n");
    printf("y = %.5lf * x + %.5lf\n", a, b);
    return 0;
}
