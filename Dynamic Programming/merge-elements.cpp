int dp[205][205];
int help(vector<int>& A,int l,int r)
{
    if(l>r)
        return 0;
    if(l==r)
        return 0;
    if(l+1 == r)
        return A[l]+A[r];
    if(dp[l][r] != -1)
        return dp[l][r];
    int sum = A[r];
    int ans = INT_MAX;
    for(int i=l;i<r;i++)
    {
        sum += A[i];
        ans = min(ans,help(A,l,i)+help(A,i+1,r));
    }
    return dp[l][r] = ans+sum;
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    memset(dp,-1,sizeof(dp));
    return help(A,0,n-1);
}
