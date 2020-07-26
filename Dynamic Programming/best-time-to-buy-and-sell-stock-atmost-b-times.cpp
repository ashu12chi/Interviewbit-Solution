int dp[501][501][2];
int solve1(vector<int>& A,int ind,int B,int state)
{
    if(ind == A.size())
        return 0;
    if(B == 0 && state == 0)
        return 0;
    if(dp[ind][B][state] != -1)
        return dp[ind][B][state];
    if(state == 1)
    {
        return dp[ind][B][state] = max(solve1(A,ind+1,B,state),A[ind]+solve1(A,ind+1,B,1-state));
    }
    return dp[ind][B][state] = max(solve1(A,ind+1,B,state),solve1(A,ind+1,B-1,1-state)-A[ind]);
}
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    if(n == 0 || n == 1)
        return 0;
    if(B>n)
        B = n;
    memset(dp,-1,sizeof(dp));
    return solve1(A,0,B,0);
}
