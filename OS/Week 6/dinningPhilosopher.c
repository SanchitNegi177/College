#include <stdio.h>

int p[5];
int ch[5];

void signal(int y)
{
    int j = (y + 1) % 5;
    p[y] = 0;
    ch[y] = 0;
    ch[j] = 0;
}

void wait(int y)
{
    int right = (y + 1) % 5;
    if ((ch[y] == 0) && (ch[right] == 0))
    {
        p[y] = 1;
        ch[y] = 1;
        ch[right] = 1;
    }
    else if (p[y] == 1)
    {
        int w;
        printf("Do you want philospher %d to stop eat (1 for Yes): ", y);
        scanf("%d", &w);
        if (w == 1)
            signal(y);
    }
    else
    {
        printf("chopstick %d %d are busy \n", y, right);
        printf("Philosopher %d waits \n", y);
    }
}

int main()
{
    int u;
    for (int i = 0; i < 5; i++)
    {
        p[i] = 0;
        ch[i] = 0;
    }
    do
    {
        for (int i = 0; i < 5; i++)
        {
            if (p[i] == 0)
            {
                printf("%d Thinking ", i);
                printf("\n");
            }
            else
            {
                printf("%d Eating", i);
                printf("\n");
            }
        }

        int s;
        printf("Who wants to eat : ");
        scanf("%d", &s);
        wait(s);

        printf("\nWant to continue,if yes press 1 : ");
        scanf("%d", &u);

    } while (u == 1);
    
    return 0;
}