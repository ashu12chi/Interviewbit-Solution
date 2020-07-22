#define ll long long
ll dp[705][705];
ll solve(string& A,string& B,int i,int j,int n,int m)
{
    if(j == m)
        return 1;
    if(i == n)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(A[i] == B[j])
        return dp[i][j] = solve(A,B,i+1,j+1,n,m) + solve(A,B,i+1,j,n,m);
    return dp[i][j] = solve(A,B,i+1,j,n,m);
}
int Solution::numDistinct(string A, string B) {
    int n = A.size();
    int m = B.size();
    memset(dp,-1,sizeof(dp));
    return solve(A,B,0,0,n,m);
}
