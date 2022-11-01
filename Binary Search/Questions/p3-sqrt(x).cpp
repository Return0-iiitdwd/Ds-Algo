// https://leetcode.com/problems/sqrtx/

#include <iostream>
using namespace std;

//Approach (Binary Search) Time: - O(logn) Space: - O(1)
class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;
        int low = 0, high = x;
        while (low <= high){
            int mid = low + (high - low) / 2;
            long long int sqMid = (long long int)mid * mid;
            if (sqMid <= x){
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
