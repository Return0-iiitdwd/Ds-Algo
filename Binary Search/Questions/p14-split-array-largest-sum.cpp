// https://leetcode.com/problems/split-array-largest-sum/
#include <iostream>
#include <vector>
using namespace std;

// Appraoch (Binary Search) Time: - O(nlog(m)) Space: - O(1) {Here m = sum of nums - highest element + 1}
class Solution
{
    bool isPossible(vector<int> &nums, int k, int sum)
    {
        int tempSum = 0;
        int seg = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > sum)
            {
                return false;
            }
            tempSum += nums[i];
            if (tempSum > sum)
            {
                tempSum = nums[i];
                seg++;
            }
        }
        return seg <= k;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        int low = 0, high = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            high += nums[i];
            low = max(low, nums[i]);
        }
        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, k, mid))
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

// There is a Dp approach as well. (You are free to google)