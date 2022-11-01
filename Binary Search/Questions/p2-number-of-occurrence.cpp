// https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1

//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

// Time: - O(logn) Space: - O(1)
class Solution
{
public:
    int count(int arr[], int n, int x)
    {
        return upper_bound(arr, arr + n, x) - lower_bound(arr, arr + n, x);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
