#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

// Floyd warshal
void shortest(vector<vector<int>> &mat)
{
    int n = mat.size();
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][via] != INF && mat[via][j] != INF)
                {
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string val;
            cin >> val;
            if (val == "INF")
            {
                matrix[i][j] = INF;
            }
            else
            {
                matrix[i][j] = stoi(val);
            }
        }
    }

    shortest(matrix);
    cout << "Shortest Distance Matrix is" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}