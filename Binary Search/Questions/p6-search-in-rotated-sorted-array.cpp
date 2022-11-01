// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

//Approach - 1 (Binary Search) Time: - O(logn) Space: - O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (nums[mid] == target){
                return mid;
            }
            //Left part is sorted
            else if (nums[mid] > nums[high]){
                //If it lies on left part
                if (target < nums[mid] && target >= nums[low]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            //Right part is sorted
            else{
                //If it lies on right part
                if (target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};