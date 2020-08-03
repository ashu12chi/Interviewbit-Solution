int Solution::findMinXor(vector<int> &ar) {
    sort(ar.begin(),ar.end());
    int n = ar.size();
    int ans = INT_MAX;
    for(int i=1;i<n;i++)
    {
        int temp = ar[i]^ar[i-1];
        ans = min(ans,temp);
    }
    return ans;
}
