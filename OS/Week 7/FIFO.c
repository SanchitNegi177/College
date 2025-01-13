
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX_SIZE 50

int main()
{
    bool valid[MAX_SIZE];            // Creating a page table
    for(int i=0;i<MAX_SIZE;i++)
        valid[i]=0;

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
    int curr=0;
    for(int i=0;i<n;i++)
    {
        if(valid[arr[i]]==1)
            hit++;
        else
        {
            pageFault++;
            if(window[curr]!=-1 )
                valid[window[curr]]=0;

            window[curr]=arr[i];
            valid[arr[i]]=1;
            curr=(curr+1)%qLimit;
        }

        
        // Printing page table
        printf(" %d : ",arr[i]);
        for(int i=0;i<qLimit;i++)
            printf("%d ",window[i]);
        printf(" -> %d \n",pageFault);
        
        
    }
    printf("%d",pageFault);

    return 0;
}
