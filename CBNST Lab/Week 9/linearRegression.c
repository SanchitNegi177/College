#include <stdio.h>

int main()
{
    int n;
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];

    printf("Enter the values of x and y:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
        sumY2 += y[i] * y[i];
    }

    double meanX = sumX / n;
    double meanY = sumY / n;

    double slopeYOnX = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double interceptYOnX = meanY - slopeYOnX * meanX;

    double slopeXOnY = (n * sumXY - sumX * sumY) / (n * sumY2 - sumY * sumY);
    double interceptXOnY = meanX - slopeXOnY * meanY;

    printf("\nRegression line (y on x): y = %.2lfx + %.2lf\n", slopeYOnX, interceptYOnX);
    printf("Regression line (x on y): x = %.2lfy + %.2lf\n", slopeXOnY, interceptXOnY);

    return 0;
}
