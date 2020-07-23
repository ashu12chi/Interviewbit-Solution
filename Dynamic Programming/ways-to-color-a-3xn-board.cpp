#define ll int
#define mod 1000000007
ll dp[123456][5][5][5];
ll solve_dp(ll index,ll prev1,ll prev2,ll prev3,ll A)
{
    if(index == A)
        return 1;
    if(dp[index][prev1][prev2][prev3]!=-1)
        return dp[index][prev1][prev2][prev3];
    ll ans = 0;
    for(int i=1;i<5;i++)
    {
        if(i == prev1)
            continue;
        for(int j=1;j<5;j++)
        {
            if(j == i || j == prev2)
                continue;
            for(int k=1;k<5;k++)
            {
                if(k == j || k == prev3)
                    continue;
                ans = (ans + solve_dp(index+1,i,j,k,A))%mod;
            }
        }
    }
    return dp[index][prev1][prev2][prev3] = ans;
}
int Solution::solve(int A) {
    memset(dp,-1,sizeof(dp));
    return solve_dp(0,0,0,0,A);
}
