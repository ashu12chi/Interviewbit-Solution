int Solution::minPathSum(vector<vector<int> > &ar) {
    int n = ar.size();
    int m = ar[0].size();
    int dp[n][m];
    dp[0][0] = ar[0][0];
    for(int i=1;i<n;i++)
        dp[i][0] = ar[i][0] + dp[i-1][0];
    for(int i=1;i<m;i++)
        dp[0][i] = ar[0][i] + dp[0][i-1];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j] = ar[i][j] + min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n-1][m-1];
    return 0;
}
