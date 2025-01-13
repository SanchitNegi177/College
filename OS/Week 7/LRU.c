
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX_SIZE 50

int main()
{
    int valid[MAX_SIZE];            // Creating a page table
    for(int i=0;i<MAX_SIZE;i++)
        valid[i]=-1;

    int n;scanf("%d",&n);       // INPUT
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int qLimit;scanf("%d",&qLimit);
    int window[qLimit];
    for(int i=0;i<qLimit;i++)
        window[i]=-1;
        

    // ALGO
    int pageFault=0,hit=0;
    for(int i=0;i<n;i++)
    {
        if(valid[arr[i]]!=-1)
        {
            valid[arr[i]]=i;
            hit++;
        }
        else
        {
            pageFault++;

            int leastUsed=1e9,windowIndex=-1;
            for(int i=0;i<qLimit;i++)
            {
                if(window[i]==-1)
                {
                    leastUsed=window[i];
                    windowIndex=i;
                    break;
                }
                if(leastUsed == 1e9 || valid[window[i]] < valid[leastUsed])
                {
                    leastUsed=window[i];
                    windowIndex=i;
                }
            }

            if(leastUsed != -1 )
                valid[leastUsed]=-1;

            window[windowIndex]=arr[i];
            valid[arr[i]]=i;
        }

        
        // Printing page table
        printf("%d : ",arr[i]);
        for(int i=0;i<qLimit;i++)
            printf("%d ",window[i]);
        printf(" -> %d \n",pageFault);

        
        
    }
    printf("%d",pageFault);

    return 0;
}
