#include <iostream>
#include <vector>
using namespace std;

// Time : - O(logn) Space : - O(1)
// Only applicable to sorted array
int binarySearch(vector<int> nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        // calculating mid like this and
        // not like (low + high) / 2 so as to
        // avoid integer overflow
        int mid = low + (high - low) / 2;

        // If found target at nums[mid]
        // Return mid
        if (nums[mid] == target)
        {
            return mid;
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
    return -1;
}

// Recursive binary search
// Time: - O(logn) space: - O(logn)
int binarySearchRecursive(vector<int> nums, int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }

    // calculating mid like this and
    // not like (low + high) / 2 so as to
    // avoid integer overflow
    int mid = low + (high - low) / 2;

    // If nums[mid] is target
    // return mid
    if (nums[mid] == target)
    {
        return mid;
    }

    // Recursive call to search in right part of array
    if (nums[mid] < target)
    {
        return binarySearchRecursive(nums, mid + 1, high, target);
    }

    // Recursive call to search in left part of array
    return binarySearchRecursive(nums, low, mid - 1, target);
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << binarySearch(arr, 8);
    return 0;
}