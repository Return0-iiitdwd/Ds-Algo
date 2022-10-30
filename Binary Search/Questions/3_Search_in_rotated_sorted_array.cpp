// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include<bits/stdc++.h>
using namespace std;
int search(vector<int>&nums, int target) {
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=(h-l)/2+l;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<nums[h]){
                if(nums[mid]<target and target<=nums[h]) l=mid+1;
                else h=mid-1;
            }
            else{
                if(nums[l]<=target and target<nums[mid]) h=mid-1;
                else l=mid+1;
            }

        }
        return -1;
}
int main(){
    vector<int> v={7,8,9,1,2,3};
    cout<<search(v,7);

}
