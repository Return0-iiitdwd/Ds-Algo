// https://leetcode.com/problems/minimum-size-subarray-sum/description/
#include<bits/stdc++.h>
using namespace std;
//this will be used to find if we can get achieve target sum by considering k elements 
bool predicate(vector<int>&nums,int k,int target){
    int sum=0;
    int n=nums.size();
    for(int i=0;i<k;i++){
        sum+=nums[i];
    }
    int max1=sum;
    int l=0,h=k;
    while(h < n){
        sum-=nums[l++];
        sum+=nums[h++];
        max1=max(max1,sum);
    }
    return target<=max1;
}
int minSubArrayLen(int target, vector<int>& nums) {
    int l=1,h=nums.size();
    while(l<h){
        int mid=(h-l)/2+l;
        if(predicate(nums,mid,target)==true){
            h=mid;
        }
        else l=mid+1;
    }        
    if(predicate(nums,l,target)==true) return l;
    return 0;
}
int main(){
    vector<int>v={2,3,1,2,4,3};
    cout<<minSubArrayLen(7,v);
}