int Solution::solve(const vector<int> &ar) {
    int n = ar.size();
    if(n<=2)
        return n;
    vector<unordered_map<int,int>> dp(n);
    int ans = 2;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            int dist = ar[i] - ar[j];
            if(dp[j].find(dist) == dp[j].end())
                dp[j][dist] = 1;
            if(dp[i].find(dist) == dp[i].end())
                dp[i][dist] = 1;
            if(dp[j][dist] + 1 > dp[i][dist])
                dp[i][dist] = dp[j][dist] + 1;
            ans = max(ans,dp[i][dist]);
        }
    }
    return ans;
}
