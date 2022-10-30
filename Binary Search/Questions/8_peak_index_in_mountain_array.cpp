// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

int peakIndexInMountainArray(vector<int>& arr) {
        int l=0;
        int h=arr.size()-1;
        while(l<h){
            int mid=(h-l)/2+l;
            if(arr[mid]<arr[mid+1]) l=mid+1;
            else h=mid;
        }
        return l;
    }