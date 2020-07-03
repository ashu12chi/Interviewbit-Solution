#define ll long long
int Solution::trap(const vector<int> &ar) {
    ll n = ar.size();
    ll ans = 0ll;
        ll mini = 0;
        ll sum = 0ll;
        for(int i=1;i<n;i++)
        {
            if(ar[i] >= ar[mini])
            {
                ans += (ar[mini]*(i-mini-1)-sum);
                mini = i;
                sum = 0;
            }
            else
            {
                sum += ar[i];
            }
        }
        ll j = mini;
        mini = n-1;
        sum = 0ll;
        for(int i=n-2;i>=j;i--)
        {
            if(ar[i] >= ar[mini])
            {
                ans += (ar[mini]*(mini-i-1)-sum);
                mini = i;
                sum = 0;
            }
            else
            {
                sum += ar[i];
            }
        }
     return ans;
}
