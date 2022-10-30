// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        while(l<h){
            int mid=(h-l)/2+l;
            if(nums[mid]<nums[h]){
                h=mid;
            }
            else{
                l=mid+1;
            }
        }
        return nums[l];
    }
int main(){
    vector<int> v={7,8,9,1,2,3};
    cout<<findMin(v);

}