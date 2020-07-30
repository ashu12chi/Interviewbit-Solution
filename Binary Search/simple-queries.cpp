#define mod 1000000007
#define ll long long
ll find(ll n)
{
    int c = 0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i == 0)
        {
            c++;
            if(i!=n/i)
                c++;
        }
    }
    return c;
}
ll power(ll a,ll b)
{
    ll res = 1;
    a =a%mod;
    while(b)
    {
        if(b%2 == 1)
            res = (res*a)%mod;
        b = b/2;
        a = (a*a)%mod;
    }
    return res;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &v) {
    int n = A.size();
    vector<ll> next_greater(n,n);
    stack<ll> s;
    s.push(0);
    next_greater[0] = -1;
    for(int i=1;i<n;i++)
    {
        while(!s.empty() && A[s.top()] <= A[i])
        {
            next_greater[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    vector<ll> prev_greater(n,-1);
    s.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        while(!s.empty() && A[s.top()] < A[i])
        {
            prev_greater[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    vector<pair<ll,ll>> ar(n);
    for (ll i = 0; i < n; i++)
    {
        ar[i].first = A[i];
        ar[i].second = ((ll)(i - prev_greater[i]))*((ll)(next_greater[i] - i));
    }
    for(int i=0;i<n;i++)
    {
        ll val = sqrt(ar[i].first);
        if(val*val == ar[i].first)
        {
            ll temp = find(ar[i].first);
            ar[i].first = power(val,temp);
        }
        else
        {
           ll temp = find(ar[i].first);
            ar[i].first = power(ar[i].first,temp/2); 
        }
    }
    sort(ar.begin(),ar.end());
    reverse(ar.begin(),ar.end());
    vector<ll> freq(n);
    freq[0] = ar[0].second;
    for(int i=1;i<n;i++)
    {
        freq[i] = freq[i-1]+ar[i].second;
    }
    vector<int> ans;
    for (int i=0;i<v.size();i++)
    {
        auto it = lower_bound(freq.begin(), freq.end(), v[i])-freq.begin();
        ans.push_back(ar[it].first);
    }
    return ans;
}
