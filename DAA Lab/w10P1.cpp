#include <bits/stdc++.h>


using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> start(n), end(n);
    for (auto &s : start)
        cin >> s;
    
    for (auto &e : end)
        cin >> e;

    vector<pair<pair<int, int>, int>> activities(n);
    for (int i = 0; i < n; ++i)
        activities[i] = {{end[i], start[i]}, i + 1};

    sort(activities.begin(), activities.end());

    vector<int> selectedIndices;
    int count = 0;
    int lastEndTime = 0;

    for (auto &activity : activities)
    {
        if (activity.first.second >= lastEndTime)
        {
            lastEndTime = activity.first.first;
            selectedIndices.push_back(activity.second);
            count++;
        }
    }

    cout <<"No. of non-conflicting activities: "<< count << endl;
    cout <<"List of selected activities:  " << endl;
    // sort(selectedIndices.begin(),selectedIndices.end());
    for (auto index : selectedIndices)
    {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
