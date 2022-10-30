#include <iostream>
#include <vector>
using namespace std;

// Time : - O(n) Space : - O(1)
int linearSearch(vector<int> nums, int target)
{
    int flag = -1, n = nums.size();

    // Iterate over all the elements
    // to find target
    for (int i = 0; i < n; i++)
    {
        // If find the target
        // Store in falg
        if (nums[i] == target)
        {
            flag = i;
            break;
        }
    }

    return flag;
}

int main()
{
    vector<int> arr{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    cout << linearSearch(arr, 8);
    return 0;
}