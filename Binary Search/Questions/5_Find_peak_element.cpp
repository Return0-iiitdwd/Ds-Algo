// https://leetcode.com/problems/find-peak-element/submissions/833503360/
#include<bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        while(l<h){
            int mid=(h-l)/2+l;
            if(nums[mid]>nums[mid+1]) h=mid;
            else l=mid+1;
        }
        return l;
    }
int main(){
    vector<int> v={1,2,3,1};
    cout<<findPeakElement(v);

}
