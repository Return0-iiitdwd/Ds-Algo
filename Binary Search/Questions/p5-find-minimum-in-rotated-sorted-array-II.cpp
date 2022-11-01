// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

#include <iostream>
#include <vector>
using namespace std;

//Approach (Binary Search) Time: - worst - O(n) Average - O(logn), space: - O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high){
            int mid = low + (high - low) / 2;

            //If nums[mid] == nums[high] we can't say 
            //in which part answer is, so we decrease high
            //and calculate mid again
            if (nums[mid] == nums[high]){
                high--;
            }
            else if (nums[mid] < nums[high]){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return nums[low];
    }
};