int Solution::solve(vector<vector<int> > &ar) {
    int n = ar.size();
    int m = ar[0].size();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    int ans = INT_MIN;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            dp[i][j] = ar[i][j] + dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1];
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
}
