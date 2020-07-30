#define ll long long
ll power(ll x,ll n,ll p)
{
    ll res = 1ll;
    x = x%p;
    while(n)
    {
        if(n%2 == 1)
            res = (res*x)%p;
        n = n/2;
        x = (x*x)%p;
    }
    return res;
}
int Solution::pow(int x,int n,int d) {
    if(x == 0)
        return 0;
   ll ans = power(x,n,d);
   ans = (ans+d)%d;
   return ans;
}
