#define ll long long
ll dp[1001][1001];
ll solve(string& A,string& B,int n,int m)
{
    if(n == 0)
        return m;
    if(m == 0)
        return n;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(A[n-1] == B[m-1])
        return dp[n][m] = solve(A,B,n-1,m-1);
    return dp[n][m] = 1 + min({solve(A,B,n-1,m-1),solve(A,B,n-1,m),solve(A,B,n,m-1)});
}
int Solution::minDistance(string A, string B) {
    memset(dp,-1,sizeof(dp));
    return solve(A,B,A.size(),B.size());
}
