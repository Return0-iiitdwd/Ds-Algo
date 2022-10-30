// https://www.spoj.com/problems/EKO/

    /*हतो वा प्राप्यसि स्वर्गम्, जित्वा वा भोक्ष्यसे महिम्।
    तस्मात् उत्तिष्ठ कौन्तेय युद्धाय कृतनिश्चय:॥*/

#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int A[N];
bool iswood(int mid,int n,long long reqwood){
    long long totalwood=0;
    for(int i=0;i<n;i++){
        if(A[i]>mid) totalwood+=A[i]-mid;
    }
    return totalwood>=reqwood;
}
int main(){
    int n;
    long long reqwood;
    cin>>n>>reqwood;
    int max1=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>A[i];
        max1=max(max1,A[i]);
    }
    int l=0,h=max1;
    int ans=-1;
    while(l<=h){
        int mid=(h-l)/2+l;

        if(iswood(mid,n,reqwood)==true){
            ans=mid;
            l=mid+1;
        }
        else h=mid-1;
    }
    cout<<ans;
    return 0;
}