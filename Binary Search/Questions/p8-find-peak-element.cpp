//https://leetcode.com/problems/find-peak-element/

#include <iostream>
#include <vector>
using namespace std;

//Approach (Binary Search) Time: - O(logn) Space: - O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high){
            int mid = low + (high - low) / 2;
            
            if (nums[mid] > nums[mid + 1]){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};