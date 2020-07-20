#define mod 10000003
#define ll long long
int Solution::seats(string A) {
    vector<int> pos;
    for(int i=0;i<A.size();i++)
    {
        if(A[i] == 'x')
            pos.push_back(i);
    }
    int n = pos.size();
    ll ans = 0ll;
    ll mid = n/2;
    for(int i=0;i<n;i++)
    {
        ans =(ans+(abs(pos[i]-pos[mid])-abs(i-mid)+mod)%mod)%mod;
    }
    return ans%mod;
}
