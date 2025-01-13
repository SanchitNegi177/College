#include <stdio.h>
#include <math.h>
float func(float x, float y)
{
    return (y * y - x * x) / (y * y + x * x);
}
int main()
{
    float x0, y0, xn, yn, k1, k2, k3, k4, k;
    int n;
    printf("Enter the value of x0\n");
    scanf("%f", &x0);
    printf("Enter the value of y0\n");
    scanf("%f", &y0);
    printf("Enter the calculating point\n");
    scanf("%f", &xn);
    printf("Enter Number of steps\n");
    scanf("%d", &n);

    float h = (xn - x0) / n;

    for (int i = 0; i < n; i++)
    {
        k1 = h * func(x0, y0);
        k2 = h * func(x0 + h / 2, y0 + k1 / 2);
        k3 = h * func(x0 + h / 2, y0 + k2 / 2);
        k4 = h * func(x0 + h, y0 + k3);
        
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        printf("The value of y at x=%f in iteration %d is %f\n", x0, i + 1, y0);
        x0 = x0 + h;
        y0 = y0 + k;
    }
    printf("The final value yn at xn %f is %f\n", x0, y0);
    return 0;
}
