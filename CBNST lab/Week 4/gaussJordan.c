#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    printf("Enter order of matrix\n");
    scanf("%d", &n);
    float mat[n][n + 1];

    for (int i = 0; i < n; i++) // input
    {
        printf("Enter row : %d\n", i + 1);
        for (int j = 0; j <= n; j++)
        {
            scanf("%f", &mat[i][j]);
        }
    }

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

    printf("Upper traingular matrix\n");
    for (int i = 0; i < n; i++) // printing matrix
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }

    // Finding values
    float ans[n];
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = mat[i][n] / mat[i][i];
    }

     printf("Solution of given equations is: \n");
    for (int i = 0; i < n; i++) // printing values
    {
        printf("%c -> %f \n", ('a' + i), ans[i]);
    }

    return 0;
}
