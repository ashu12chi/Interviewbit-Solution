#define ll long long
int Solution::solve(int n, vector<int> &ar) {
    ll suffix[n];
    suffix[n-1] = ar[n-1];
    for(int i=n-2;i>=0;i--)
    {
        suffix[i] = suffix[i+1];
        suffix[i] += ar[i];
    }
    ll sum = suffix[0];
    if(sum%3!=0)
        return 0;
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        if(suffix[i] == sum/3)
            v.push_back(i);
    }
    if(sum == 0)
    {
        ll t = v.size();
        return (t-1)*(t-2)/2;
    }
    ll sum1 = 0ll;
    ll ans = 0ll;
    for(int i=0;i<n;i++)
    {
        sum1 += ar[i];
        if(sum1 == sum/3)
        {
            ans += v.size()-(upper_bound(v.begin(),v.end(),i)-v.begin());
        }
    }
    return ans;
}
