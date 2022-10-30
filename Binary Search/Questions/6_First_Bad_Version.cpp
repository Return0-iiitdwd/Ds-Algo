// https://leetcode.com/problems/first-bad-version/
int firstBadVersion(int n) {
        int l=1,h=n;
        while(l<h){
            int mid=(h-l)/2+l;
            if(isBadVersion(mid)==true) h=mid;
            else l=mid+1;
        }
        return l;
    }