#include <bits/stdc++.h>
using namespace std;

int minimumValIndex(vector<int> v, int i)
{
    int n=v.size();
    if (i == n-1 )
        return i;
    int mini=minimumValIndex(v, i + 1);
    return v[mini]<v[i]?mini:i;
}

// void minimumValIndex(vector<int> v, int i,int mini)
// {
//     int n=v.size();
//     if (i == n-1 )
//         return mini;
//     if(v[mini]>v[i])
//         mini=i;
//     minimumValIndex(v,i+1,mini);
// }

void selectionSortRecursion(vector<int> &v, int i)
{
    int n = v.size();
    if (i == n-1)
        return;
    int minIndex = minimumValIndex(v, i);
    swap(v[minIndex], v[i]);
    selectionSortRecursion(v, i + 1);
}

vector<int> selectionSortLoop(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i + 1;
        for (int j = i ; j < n; j++)
        {
            if (v[minIndex] > v[j])
            {
                minIndex = j;
            }
        }
        swap(v[minIndex], v[i]);
    }

    cout << "Selection Sort By loops\n";
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

    selectionSortLoop(v);
    selectionSortRecursion(v, 0);
    cout << "Selection Sort By Recursion\n";
    for (auto it : v)
        cout << it << " ";
    cout << endl;
    return 0;
}