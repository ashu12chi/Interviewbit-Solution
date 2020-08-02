#define ll long long
#define mod 1000000007
int Solution::cntBits(vector<int> &A) {
    int n = A.size();
    ll bits[31];
    memset(bits,0ll,sizeof(bits));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<31;j++)
        {
            if(A[i]&(1<<j))
                bits[j]++;
        }
    }
    ll ans = 0ll;
    for(int i=0;i<31;i++)
    {
        ans = (ans + ((n-bits[i])*bits[i])%mod)%mod;
    }
    return (ans*2)%mod;
}
