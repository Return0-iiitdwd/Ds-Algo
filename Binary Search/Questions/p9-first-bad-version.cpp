// https://leetcode.com/problems/first-bad-version/
#include <iostream>
#include <vector>
using namespace std;

//This API isBadVersion is defined for you.
bool isBadVersion(int n);

// Appraoch (Binary Search) Time: - O(logn) Space: - O(1)

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int low = 1, high = n;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};