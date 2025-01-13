#include <stdio.h>

void gauss(int n, double mat[n][n + 1], double solution[n])
{
    for (int i = 0; i < n; i++) // Gauss Jorden
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                float c = mat[i][j] / mat[j][j];

                for (int k = 0; k <= n; k++)
                {
                    mat[i][k] = mat[i][k] - c * mat[j][k];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                float c = mat[i][j] / mat[j][j];

                for (int k = 0; k <= n; k++)
                {
                    mat[i][k] = mat[i][k] - c * mat[j][k];
                }
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        solution[i] = mat[i][n] / mat[i][i];
    }
}

int main()
{
    int numPoints;
    printf("Enter the number of data points: ");
    scanf("%d", &numPoints);

    double x[numPoints], y[numPoints];
    printf("Enter the x and y values:\n");
    for (int i = 0; i < numPoints; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double sumX = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0;
    double sumY = 0, sumXY = 0, sumX2Y = 0;

    for (int i = 0; i < numPoints; i++)
    {
        sumX += x[i];
        sumX2 += x[i] * x[i];
        sumX3 += x[i] * x[i] * x[i];
        sumX4 += x[i] * x[i] * x[i] * x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2Y += x[i] * x[i] * y[i];
    }

    double matrix[3][4] = {
        {numPoints, sumX, sumX2, sumY},
        {sumX, sumX2, sumX3, sumXY},
        {sumX2, sumX3, sumX4, sumX2Y}};

    double ans[3];
    gauss(3, matrix, ans);

    printf("\nThe fitted parabolic curve is: y = %.2lfx^2 + %.2lfx + %.2lf\n",
           ans[2], ans[1], ans[0]);

    return 0;
}
