#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, key, comparison = 0, count = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> key;

        int low = 0, high = 0, ok = 0;
        while (high < n)
        {
            comparison++;
            if (key < arr[high])
                break;
            else if (key > arr[high])
            {
                count++;
                low = high;
                high = pow(2, count);
            }
            else
            {
                ok = 1;
                break;
            }
        }

        if (!ok)
        {
            for (int i = low + 1; i < n; i++)
            {
                comparison++;
                if (arr[i] == key)
                {
                    ok = 1;
                    break;
                }
            }
        }

        if (ok)
        {
            cout << "Present\nComparison: " << comparison << endl;
        }
        else
        {
            cout << "Not Present\nComparison: " << comparison << endl;
        }
    }
}
