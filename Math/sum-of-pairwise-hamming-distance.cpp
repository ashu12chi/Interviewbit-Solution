#define mod 1000000007
#define ll long long
int Solution::hammingDistance(const vector<int> &A) {
    ll ans=0;
    ll n=A.size();
    for(int i=0;i<31;i++)
    {
        ll count=0;
        for(int j=0;j<n;j++)
        {
            if(A[j]&(1<<i))
                count++;
        }
        ans=(ans+count*(n-count)*2)%mod;
    }
    return ans;
}
