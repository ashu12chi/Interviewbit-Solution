#define ll long long
#define mod 1000000007
ll dp[1000][10000];
ll solve_dp(ll pos,ll sum,ll A,ll B)
{
    if(sum > B)
        return 0;
    if(pos == A)
    {
        if(sum == B)
            return 1;
        return 0;
    }
    if(dp[pos][sum]!=-1)
        return dp[pos][sum];
    ll ans = 0ll;
    for(int i=0;i<=9;i++)
    {
        ans = (ans + solve_dp(pos+1,sum+i,A,B))%mod;
    }
    return dp[pos][sum] = ans;
}
int Solution::solve(int A, int B) {
    memset(dp,-1,sizeof(dp));
    ll ans1 = solve_dp(0,0,A,B);
    memset(dp,-1,sizeof(dp));
    ll ans2 = solve_dp(0,0,A-1,B);
    ll ans = (ans1-ans2+mod)%mod;
    return ans;
}
