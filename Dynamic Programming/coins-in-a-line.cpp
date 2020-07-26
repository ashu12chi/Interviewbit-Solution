int dp[502][502][2];
int solve(vector<int> &A,int i,int j,int player)
{
    if(i>=j)
        return 0;
    if(dp[i][j][player]!=-1)
        return dp[i][j][player];
    if(player == 0)
    {
        int val1 = A[i] + solve(A,i+1,j,1-player);
        int val2 = A[j] + solve(A,i,j-1,1-player);
        return dp[i][j][player] = max(val1,val2);
    }
    int val1 = solve(A,i+1,j,1-player);
    int val2 = solve(A,i,j-1,1-player);
    return dp[i][j][player] = min(val1,val2);
}
int Solution::maxcoin(vector<int> &A) {
    memset(dp,-1,sizeof(dp));
    return solve(A,0,A.size()-1,0);
}
