#include <iostream>
#include <vector>
using namespace std;

// Upper bound of x => first element greater than x
// If array is 1, 3, 4, 6, 6, 7, 9
// Upper bound of 6 is 7
// Upper bound of 4 is first 6
// Upper bound of 9 is X (null) we return index of last element + 1
// Upper bound of 10 is X(null) we return index of last element + 1

// Time: - O(logn) Space: - O(1)
int upperBound(vector<int> nums, int x)
{
    int low = 0, high = nums.size() - 1;
    int ans = nums.size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // If nums[mid] is equal to x
        // We search for upper bound in left part
        if (nums[mid] <= x)
        {
            low = mid + 1;
        }

        // If nums[mid] is greater than x
        // save mid and search in left part
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr{1, 3, 4, 6, 6, 7, 9};
    cout << upperBound(arr, 6) << endl;
    cout << upperBound(arr, 4) << endl;
    cout << upperBound(arr, 9) << endl;
    cout << upperBound(arr, 10) << endl;
    return 0;
}