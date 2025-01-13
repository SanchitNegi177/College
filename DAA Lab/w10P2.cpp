#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> times(n), deadlines(n);
    for (int i = 0; i < n; ++i)
        cin >> times[i];

    for (int i = 0; i < n; ++i)
        cin >> deadlines[i];

    vector<pair<pair<int, int>, int>> tasks(n);
    for (int i = 0; i < n; ++i)
    {
        tasks[i] = {{deadlines[i], times[i]}, i + 1};
    }

    sort(tasks.begin(), tasks.end());

    priority_queue<pair<int, int>> maxHeap;
    int totalTime = 0;
    vector<int> selectedIndices;

    for (auto &task : tasks)
    {
        int duration = task.first.second;
        int deadline = task.first.first;
        int index = task.second;

        // If the current task can be completed within its deadline, add it to the heap
        if (totalTime + duration <= deadline)
        {
            maxHeap.push({duration, index});
            totalTime += duration;
            selectedIndices.push_back(index);
        }

        // If the current task cannot be completed within its deadline, consider replacing a longer task
        else if (!maxHeap.empty() && maxHeap.top().first > duration)
        {
            // Remove the longest duration task from the total time and the heap
            totalTime -= maxHeap.top().first;
            auto it = find(selectedIndices.begin(), selectedIndices.end(), maxHeap.top().second);
            if (it != selectedIndices.end())
            {
                selectedIndices.erase(it);
            }
            
            maxHeap.pop();
            // Add the current task's duration to the heap and total time
            maxHeap.push({duration, index});
            totalTime += duration;
            selectedIndices.push_back(index);
        }
    }

    cout << "Maximum number of tasks that can be completed: " << maxHeap.size() << endl;
    sort(selectedIndices.begin(), selectedIndices.end());
    cout << "Selected task number: "<< endl;
    for (int index : selectedIndices)
        cout << index << " ";
    cout << endl;

    return 0;
}
