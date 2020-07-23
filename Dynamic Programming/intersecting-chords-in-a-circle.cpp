#define ll long long
#define mod 1000000007
int Solution::chordCnt(int A) {
    ll n = 2*A;
    ll dp[n+1] = {0};
    dp[0] = dp[2] = 1ll;
    for(int i=4;i<=n;i+=2)
    {
        for(int j=0;j<i-1;j+=2)
        {
            dp[i] = (dp[i] + (dp[j]*dp[i-j-2])%mod)%mod;
        }
    }
    return dp[n];
}
