#define ll long long
ll dp[152][152][152];
ll solve(string& A,string& B,string& C,int i,int j,int k)
{
    if(k == C.size() && i == A.size() && j == B.size())
        return 1;
    if(i == A.size() && j == B.size())
        return 0;
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    if(i == A.size())
    {
        if(B[j] == C[k])
            return dp[i][j][k] = solve(A,B,C,i,j+1,k+1);
        return dp[i][j][k] = 0;
    }
    if(j == B.size())
    {
        if(A[i] == C[k])
            return dp[i][j][k] = solve(A,B,C,i+1,j,k+1);
        return dp[i][j][k] = 0;
    }
    if(A[i] != C[k] && B[j] != C[k])
        return dp[i][j][k] = 0;
    ll ans = 0;
    if(A[i] == C[k])
        ans += solve(A,B,C,i+1,j,k+1);
    if(B[j] == C[k])
        ans += solve(A,B,C,i,j+1,k+1);
    if(ans)
        return dp[i][j][k] = 1;
    return dp[i][j][k] = 0;
}
int Solution::isInterleave(string A, string B, string C) {
    memset(dp,-1ll,sizeof(dp));
    return solve(A,B,C,0,0,0);
}
