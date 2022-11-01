// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
#include <iostream>
#include <vector>
using namespace std;

// Approach (Binary Search) Time: - O(nlogm) Space: - O(1) {Here m is max element in nums}
class Solution
{
    bool isSmall(vector<int> &nums, int threshold, int div)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] / div + (nums[i] % div != 0);
        }
        return sum <= threshold;
    }

public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int high = 0;

        // High will be set to max possible value
        // in the array
        for (int i = 0; i < nums.size(); i++)
        {
            high = max(high, nums[i]);
        }

        int low = 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;

            // If we find the divisor we will move to
            // left part to search of we can get even
            // better divisor
            if (isSmall(nums, threshold, mid))
            {
                high = mid;
            }
            else // we will search for divisor in right part
            {
                low = mid + 1;
            }
        }
        return low;
    }
};