#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (1 / (1 + x * x));
}

float result(int n, float h, float lower, float upper)
{
    float sumOdd = 0.0;
    float sumEven = 0.0;
    float itr1 = lower + h;
    // float itr2 = lower + 2 * h;

    // for (int i = 1; i < n - 1; i = i + 2)
    // {
    //     sumOdd += f(itr1);
    //     itr1 += 2 * h;
    // }

    // for (int i = 2; i < n - 1; i = i + 2)
    // {
    //     sumEven += f(itr2);
    //     itr2 += 2 * h;
    // }

    for (int i = 1; i < n - 1; i++)
    {
        if(i%2)
            sumOdd += f(itr1);
        else
            sumEven += f(itr1);
        itr2 += h;
    }

    float answer = (h / 3) * ((f(lower) + f(upper)) + 4 * sumOdd + 2 * sumEven);

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
