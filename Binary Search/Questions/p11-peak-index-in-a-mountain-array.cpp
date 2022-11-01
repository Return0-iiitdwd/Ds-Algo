// https://leetcode.com/problems/peak-index-in-a-mountain-array/
#include <iostream>
#include <vector>
using namespace std;

// Appraoch (Binary Search) Time: - O(logn) Space: - O(1)
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] > arr[mid + 1])
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