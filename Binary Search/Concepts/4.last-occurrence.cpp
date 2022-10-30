#include <iostream>
#include <vector>
using namespace std;

// Time : - O(logn) Space : - O(1)
// Only applicable to sorted array
int lastOccurrence(vector<int> nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // If found target at nums[mid]
        // Save the index in ans
        // Search in right part of mid
        // To find last Occurence
        if (nums[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        // Target lies at right part of mid
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        // Target lies at left part od mid
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

// If we observe carefully we will see that we dont need
// to maintain ans, at the end high will always point to
// the first accurence, so we can write updated code as: -
int lastOccurrence2(vector<int> nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] <= target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (high >= 0 && high < nums.size() && nums[high] == target)
    {
        return high;
    }
    return -1;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 8, 8, 8, 8, 8, 10};
    cout << lastOccurrence(arr, 8);
    return 0;
}