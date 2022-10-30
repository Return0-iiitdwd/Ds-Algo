// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
#include<bits/stdc++.h>
using namespace std;
bool search(vector<int>&nums, int target) {
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=(h-l)/2+l;
            if(nums[mid]==target) return true;
            else if(nums[mid]==nums[h]) h--;
            else if(nums[mid]<nums[h]){
                if(target>nums[mid] and target<=nums[h]) l=mid+1;
                else h=mid-1;
            }
            else{
                if(target>=nums[l] and target<nums[mid]) h=mid-1;
                else l=mid+1;
            }
        }
        return false;
}
int main(){
    vector<int> v={2,5,6,0,0,1,2};
    cout<<search(v,0);

}
