// https://leetcode.com/problems/minimum-size-subarray-sum/

#include <iostream>
#include <vector>
using namespace std;

//Approach - 1 (Brute force) Time: - O(n^3) Space: - O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                int sum = 0;
                for (int k = i; k <= j; k++){
                    sum += nums[k];    
                }
                if (sum >= target){
                    ans = min(ans, j - i + 1);
                }
            }
        }
        return ans == INT_MAX? 0: ans;
    }
};

//Approach - 2 (Prefix Sum) Time: - O(n^2) Space: - O(n)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> prefix(nums.size() + 1);
        prefix[0] = 0;
        for (int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                int sum = prefix[j + 1] - prefix[i];
                if (sum >= target){
                    ans = min(ans, j - i + 1);
                }
            }
        }
        return ans == INT_MAX? 0: ans;
    }
};

//Approach - 3 (Binary Search) Time: - O(nlogn) Space: - O(1)
class Solution {
    bool isMakingSum(vector<int>& nums, int target, int size){
        int sum = 0;
        for (int i = 0; i < size; i++){
            sum += nums[i];
        }
        if (sum >= target){
            return true;
        }
        int start = 0;
        int maxi = sum;
        for (int i = size; i < nums.size(); i++){
            sum += nums[i];
            sum -= nums[start++];
            maxi = max(maxi, sum);
        }
        return maxi >= target;
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0, high = nums.size();
        int ans = 0;
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (isMakingSum(nums, target, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};

//Approach - 4 (Two pointers - Sliding window) Time: - O(n) Space: - O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, n = nums.size();
        int sum = 0, ans = INT_MAX;
        for (int i = 0; i < n; i++){
            sum += nums[i];
            while (sum >= target){
                ans = min(ans, i - start + 1);
                sum -= nums[start++];
            }
        }
        return ans == INT_MAX? 0: ans;
    }
};