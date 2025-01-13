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

    printf("Enter order of matrix\n");
    float error;
    scanf("%f", &error);

    for (int i = 0; i < n; i++) // finding if soln exists or not {diagonal dominant}
    {
        float sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                sum += fabs(mat[i][j]);
        }
        if (fabs(sum) > fabs(mat[i][i]))
        {
            printf("Solution will not converge\n");
            return 0;
        }
    }

    float res[n], prev[n]; // to store new value of res and previous value of res
    for (int i = 0; i < n; i++)
    {
        res[i] = prev[i] = 0.0;
    }

    int iter = 0;
    while (1) // Gauss Seidal
    {
        iter++;

        for (int i = 0; i < n; i++)
        {
            prev[i] = res[i];
            float sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    sum += mat[i][j] * res[j];
            }
            res[i] = ((mat[i][n] - sum) / mat[i][i]);

        }

        int ok = 0;
        for (int i = 0; i < n; i++)
        {
            if (fabs(fabs(prev[i]) - fabs(res[i])) <= error && prev[0] != 0) // checking for allowed error
                ok++;
        }
        
        if (ok == n)
            break;

        printf("Iteration %d :\n", iter);
        for (int i = 0; i < n; i++) // printing values
        {
            printf("%c -> %f \n", ('a' + i), res[i]);
        }
        printf("\n");
    }

    printf("Found at %d iteration , Solution of given equations is: \n", iter);
    for (int i = 0; i < n; i++) // printing values
    {
        printf("%c -> %f \n", ('a' + i), res[i]);
    }

    return 0;
}
