#include <bits/stdc++.h>
using namespace std;

int findOccurance( vector<int> nums, int target, string s)
{
    int n = nums.size();
    int left = 0, right = n - 1;
    int position = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            position = mid;
            if (s == "first")
                right = mid - 1;
            else if (s == "last")
                left = mid + 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return position;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int target;
    cin >> target;

    int first = findOccurance(nums, target, "first");
    int last = findOccurance(nums, target, "last");
    if (first == -1)
    {
        cout << "Key not present\n";
    }
    else
    {
        cout << nums[first] << " - " << last - first + 1 << endl;
    }
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
