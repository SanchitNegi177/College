#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &nums, int low, int high)
{
    srand(time(0));
    int random_index = low + rand() % (high - low + 1);
    swap(nums[random_index], nums[high]);
    int pivot = nums[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (nums[j] <= pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[high]);
    return (i + 1);
}

int kth_smallest(vector<int> &nums, int low, int high, int k)
{
    if (k > 0 && k <= high - low + 1)
    {
        int pivot = partition(nums, low, high);

        if (pivot - low == k - 1)   //  smallest kth largest
            return nums[pivot];
        if (pivot - low > k - 1)
            return kth_smallest(nums, low, pivot - 1, k);
        return kth_smallest(nums, pivot + 1, high, k - pivot + low - 1);

        // if (high - pivot == k - 1) // finding kth largest
        //     return nums[pivot];
        // if (high - pivot > k - 1)
        //     return kth_largest(nums, pivot + 1, high, k);
        // return kth_largest(nums, low, pivot - 1, k - high + pivot - 1));
    }
    return -1;
}

int kth_largest(vector<int> &nums, int low, int high, int k)
{
    if (k > 0 && k <= high - low + 1)
    {
        int pivot = partition(nums, low, high);

        if (high - pivot == k - 1) // finding kth largest
            return nums[pivot];
        if (high - pivot > k - 1)
            return kth_largest(nums, pivot + 1, high, k);
        return kth_largest(nums, low, pivot - 1, k - high + pivot - 1);
    }
    return -1;
}

void solve()
{
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cin >> k;

    int kth_smallest_element = kth_smallest(nums, 0, n - 1, k);
    if (kth_smallest_element == -1)
    {

        cout << "Not Present" << endl;
    }
    else
    {

        cout << "Kth smallest element: " << kth_smallest_element << endl;
    }

    int kth_largest_element = kth_largest(nums, 0, n - 1, k);
    if (kth_largest_element == -1)
    {

        cout << "Not Present" << endl;
    }
    else
    {

        cout << "Kth largest element: " << kth_largest_element << endl;
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