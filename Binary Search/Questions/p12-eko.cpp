// https://www.spoj.com/problems/EKO/

#include <iostream>
#include <vector>
#define endl "\n"
#define int long long int
using namespace std;


bool isPossible(vector<int>& heights, int m, int h){
    int wood = 0;
    for (int i = 0; i < heights.size(); i++){
        int amt = heights[i] - h;
        wood += (amt < 0? 0: amt);
    }
    return wood >= m;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> heights(n);
    for (int i = 0; i < n; i++){
        cin >> heights[i];
    }
    int low = 0, high = 0;
    for (int i = 0; i < n; i++){
        high = max(high, heights[i]);
    }
    int ans = 0;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (isPossible(heights, m, mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout << ans << endl;
}

int32_t main(){
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
}