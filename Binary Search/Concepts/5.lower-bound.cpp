#include <iostream>
#include <vector>
using namespace std;

//Lower bound of x => First element greater than or equal to x
//If array is 1, 2, 3, 4, 7, 9, 10
//Lower bound of 7 is 7
//Lower bound of 8 is 9
//Lower bound of 11 is X (null)

//Time: - O(logn) Space: - O(1)
int lowerBound(vector<int> nums, int x){
    int low = 0, high = nums.size() - 1;
    int ans = nums.size();
    while (low <= high){
        int mid = low + (high - low) / 2;

        //If nums[mid] is greater than equal to x
        //save mid and search in left part
        if (nums[mid] >= x){
            ans = mid;
            high = mid - 1;
        }

        //Search in right part
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr{1, 2, 3, 4, 7, 9, 10};
    cout << lowerBound(arr, 7) << endl;
    cout << lowerBound(arr, 8) << endl;
    cout << lowerBound(arr, 11) << endl;
    return 0;
}