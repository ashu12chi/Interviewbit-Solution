#define mod 1003
int dp[152][152][2];
int solve(string& A,int i,int j,int state)
{
    if(i>j)
        return 0;
    if(i == j)
    {
        if(state == 1)
            return A[i] == 'T';
        return A[i] == 'F';
    }
    if(dp[i][j][state] != -1)
        return dp[i][j][state];
    int ans = 0;
    for(int k=i+1;k<j;k+=2)
    {
        int left_true = solve(A,i,k-1,1);
        int right_true = solve(A,k+1,j,1);
        int left_false = solve(A,i,k-1,0);
        int right_false = solve(A,k+1,j,0);
        if(state == 0)
        {
            if(A[k] == '|')
            {
                ans = (ans + (left_false*right_false)%mod)%mod;
            }
            else if(A[k] == '^')
            {
                ans = (ans + (left_true*right_true)%mod)%mod;
                ans = (ans + (left_false*right_false)%mod)%mod;
            }
            else
            {
                ans = (ans + (left_false*right_false)%mod)%mod;
                ans = (ans + (left_true*right_false)%mod)%mod;
                ans = (ans + (left_false*right_true)%mod)%mod;
            }
        }
        else
        {
            if(A[k] == '|')
            {
                ans = (ans + (left_true*right_false)%mod)%mod;
                ans = (ans + (left_true*right_true)%mod)%mod;
                ans = (ans + (left_false*right_true)%mod)%mod;
            }
            else if(A[k] == '^')
            {
                ans = (ans + (left_true*right_false)%mod)%mod;
                ans = (ans + (left_false*right_true)%mod)%mod;
            }
            else
            {
                ans = (ans + (left_true*right_true)%mod)%mod;
            }
        }
    }
    return dp[i][j][state] = ans;
}
int Solution::cnttrue(string A) {
    memset(dp,-1,sizeof(dp));
    return solve(A,0,A.size()-1,1);
}
