#define ll long long
#define mod 1000000007
ll dp[105][105];
ll dp2[105];
ll help(ll n)
{
    if(n<=2)
        return 1;
    if(dp2[n] != -1)
        return dp2[n];
    ll count = n/2;
    if(ceil(log2(n+1)) != floor(log2(n+1)))
    {
        ll val = log2(n+1);
        ll diff = n+1 - (1<<val);
        if(diff <= pow(2,val-1))
            count = pow(2,val-1)-1+diff;
        else
            count = pow(2,val)-1;
    }
    ll ans = dp[n-1][count];
    ll temp1 = help(count);
    ll temp2 = help(n-1 - count);
    ans = (ans*temp1)%mod;
    ans = (ans*temp2)%mod;
    return dp2[n] = ans;
}
int Solution::solve(int A) {
    for(int i=0;i<=100;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%mod;
        }
    }
    memset(dp2,-1ll,sizeof(dp2));
    return help(A);
}
