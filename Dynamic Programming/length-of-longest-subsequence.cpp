int Solution::longestSubsequenceLength(const vector<int> &ar) {
    int n = ar.size();
    int lis[n];
    lis[0] = 1;
    for(int i=1;i<n;i++)
    {
        lis[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(lis[i] < lis[j]+1 && ar[j] < ar[i])
                lis[i] = lis[j] + 1;
        }
    }
    int lds[n];
    lds[n-1] = 1;
    for(int i=n-2;i>=0;i--)
    {
        lds[i] = 1;
        for(int j=n-1;j>i;j--)
        {
            if(lds[i] < lds[j] + 1 && ar[j] < ar[i])
                lds[i] = lds[j] + 1;
        }
    }
    int ans = max(lis[0],lds[n-1]);
    for(int i=1;i<n-1;i++)
    {
        ans = max(ans,lis[i]+lds[i]-1);
    }
    return ans;
}
