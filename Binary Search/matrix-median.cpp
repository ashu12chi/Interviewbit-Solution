#define ll long long
int Solution::findMedian(vector<vector<int> > &ar) {
    int n = ar.size();
    int m = ar[0].size();
    int low = 1000000005;
    for(int i=0;i<n;i++)
        low = min(low,ar[i][0]);
    int high = 1ll;
    for(int i=0;i<n;i++)
        high = max(high,ar[i][m-1]);
    int median = (n*m+1)/2;
    while(low<high)
    {
        int mid = low +(high-low)/2;
        int place = 0;
        for(int i=0;i<n;i++)
            place += upper_bound(ar[i].begin(),ar[i].end(),mid) - ar[i].begin();
        if(place < median)
            low = mid+1;
        else
            high = mid;
    }
    return low;
}
