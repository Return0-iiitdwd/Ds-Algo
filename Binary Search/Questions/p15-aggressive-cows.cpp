// https://www.spoj.com/problems/AGGRCOW/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach - (binary Search) Time: - O(nlogm) Space: - O(1)
bool isPossible(vector<int> &stalls, int c, int dis)
{
    int count = 1, start = 0;
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - stalls[start] >= dis)
        {
            count++;
            start = i;
        }
    }
    return count >= c;
}

void solve()
{
    int n, c, ans = -1;
    cin >> n >> c;
    vector<int> stalls(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[n - 1] - stalls[0];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(stalls, c, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
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