// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

//Approach - 1 (Linear Search) Time: - O(n), Space: - O(1)
//Searching for min
class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++){
            mini = min(mini, nums[i]);
        }
        return mini;
    }
};

//Searching for point of rotation
class Solution {
public:
    int findMin(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] < nums[i - 1]){
                return nums[i];
            }
        }
        return nums[0];
    }
};

//Approach - 2 (Binary Search) Time: - O(logn) Space: - O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high){
            int mid = low + (high - low) / 2;

            //The elements on right of mid will be bigger and 
            //cannot be the answer. mid can be the answer so 
            //we included it.
            if (nums[mid] < nums[high]){
                high = mid;
            }

            //Here elements on left side including the mid 
            //cannot be the anwer.
            else{
                low = mid + 1;
            }
        }
        //At last both low and high will point to the smallest element
        return nums[low];
    }
};