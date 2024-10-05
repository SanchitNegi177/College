#include <bits/stdc++.h>
using namespace std;

void swapAdj(vector<int> &v,int i,int j)
{
    int n=v.size();
    if (j >= n-1-i)
        return ;
    if(v[j]>v[j+1])
        swap(v[j],v[j+1]);
    swapAdj(v,i,j+1);
}

void bubbleSortRecursion(vector<int> &v, int i)
{
    int n = v.size();
    if (i == n-1)
        return;
    swapAdj(v,i,0);
    bubbleSortRecursion(v, i+1);
}

vector<int> bubbleSortLoop(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0 ; j < n-1-i; j++)
        {
            if (v[j] > v[j+1])
            {
                swap(v[j],v[j+1]);
            }
        }
    }

    cout << "Bubble Sort By loops\n";
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    bubbleSortLoop(v);
    bubbleSortRecursion(v, 0);
    cout << "Selection Sort By Recursion\n";
    for (auto it : v)
        cout << it << " ";
    cout << endl;
    return 0;
}