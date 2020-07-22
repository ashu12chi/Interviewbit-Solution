#define ll long long
ll dp[1001][1001];
ll solve1(string& A,string& B,int i,int j)
{
    if(i == A.size() || j == B.size())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(A[i] == B[j])
        return dp[i][j] = 1 + solve1(A,B,i+1,j+1);
    return dp[i][j] = max(solve1(A,B,i,j+1),solve1(A,B,i+1,j));
}
int Solution::solve(string A) {
    memset(dp,-1,sizeof(dp));
    string B = A;
    reverse(B.begin(),B.end());
    return solve1(A,B,0,0);
}
