#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;
string X, Y;

// Function to find the length of LCS using memoization
int lcsLength(int i, int j)
{
    if (i == 0 || j == 0)
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];


    if (X[i - 1] == Y[j - 1])
        memo[i][j] = 1 + lcsLength(i - 1, j - 1);
    else
        memo[i][j] = max(lcsLength(i - 1, j), lcsLength(i, j - 1));

    return memo[i][j];
}

int lcs(string X, string Y, int m, int n)
{

    // Initializing a matrix of size
    // (m+1)*(n+1)
    int L[m + 1][n + 1];

    // Following steps build L[m+1][n+1]
    // in bottom up fashion. Note that
    // L[i][j] contains length of LCS of
    // X[0..i-1] and Y[0..j-1]
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // L[m][n] contains length of LCS
    // for X[0..n-1] and Y[0..m-1]
    return L[m][n];
}

// Function to retrieve the LCS string using the memo table
string getLCS(int i, int j)
{
    string lcsStr;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcsStr.push_back(X[i - 1]);
            i--;
            j--;
        }
        else if (memo[i - 1][j] > memo[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(lcsStr.begin(), lcsStr.end());
    return lcsStr;
}

int main()
{
    cout << "Enter the first string: ";
    cin >> X;
    cout << "Enter the second string: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    memo.assign(m + 1, vector<int>(n + 1, -1));

    int length = lcsLength(m, n);
    string lcsStr = getLCS(m, n);

    cout << "Length of LCS: " << length << endl;
    cout << "LCS: " << lcsStr << endl;

    return 0;
}
