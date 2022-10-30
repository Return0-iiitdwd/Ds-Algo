// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
#include<bits/stdc++.h>
using namespace std;
 int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        while(l<h){
            int mid=(h-l)/2+l;
            if(nums[mid]==nums[h]) h--;
            else if(nums[mid]<nums[h]) h=mid;
            else l=mid+1;
        }
        return nums[l];
    }
int main(){
    vector<int> v={2,2,2,0,1};
    cout<<findMin(v);

}