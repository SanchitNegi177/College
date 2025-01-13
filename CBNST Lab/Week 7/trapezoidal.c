#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (1 / (1 + x * x));
}

float result(int n, float h, float lower, float upper)
{
    float sum = 0.0;
    float x = lower + h;

    for (int i = 1; i < n - 1; i++)
    {
        sum += f(x);
        x += h;
    }

    float answer = (h / 2)((f(lower) + f(upper)) + 2(sum));

    return answer;
}

int main()
{
    int n;
    float upper_limit, lower_limit;

    printf("Enter the lower and upper limit of the integral, respectively: ");
    scanf("%f %f", &lower_limit, &upper_limit);
    printf("Enter the number of points: ");
    scanf("%d", &n);

    float h = (upper_limit - lower_limit) / (n - 1);

    printf("The value of the integral is %f\n", result(n, h, lower_limit, upper_limit));

    return 0;
}
