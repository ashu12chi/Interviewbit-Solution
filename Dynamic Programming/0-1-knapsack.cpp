int dp[1001][1001];
int help(vector<int>& A,vector<int>& B,int C,int ind)
{
    if(ind == A.size())
        return 0;
    if(dp[ind][C] != -1)
        return dp[ind][C];
    if(B[ind] <= C)
        return dp[ind][C] = max(help(A,B,C,ind+1),help(A,B,C-B[ind],ind+1)+A[ind]);
    return dp[ind][C] = help(A,B,C,ind+1);
}
int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    memset(dp,-1,sizeof(dp));
    return help(A,B,C,0);
}
