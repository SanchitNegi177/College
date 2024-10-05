#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

using namespace std;

const string kInputFilename = ".txt"; // change it to respective input file
const string kOutputFilename = "output.txt";

ifstream fin(kInputFilename);
ofstream fout(kOutputFilename);

// use fin and fout

#ifdef ONLINE_JUDGE
#define bug(...)
#else
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#endif

void solve()
{
    
}


int main()
{
    int T;
    fin >> T;

    for (int case_idx = 1; case_idx <= T; ++case_idx)
    {
        fout << "Case #" << case_idx << ": ";
        solve();
    }

}