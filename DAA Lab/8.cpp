#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int comparisons=0,swaps=0;
    for(int i=0;i<n-1;i++)          // Selection sort
    {
        int minIndex=i;
        for(int j=i+1;j<n;j++)
        {
            comparisons++;
            if(nums[minIndex]>nums[j])
                minIndex=j;
        }
        swap(nums[minIndex],nums[i]);
        swaps++;
    }

    for(int it:nums)
        cout<<it<<" ";
    cout<<endl;
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Swaps: "<<swaps<<endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
