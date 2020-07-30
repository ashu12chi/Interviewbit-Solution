#define mod 10000003
#define ll long long
int Solution::paint(int A, int B, vector<int> &C) {
    ll low = 0ll;
    ll high = 0ll;
    for(int i=0;i<C.size();i++)
    {
        high += C[i];
        low = max(low,(ll)C[i]);
    }
    ll target = 0ll;
    while(low<=high)
    {
        ll mid = (low+high)/2;
        ll num = 1ll;
        ll sum = 0ll;
        for(int i=0;i<C.size();i++)
        {
            if(sum+C[i] > mid)
            {
                sum = C[i];
                num++;
            }
            else
                sum += C[i];
        }
        if(num <= A)
        {
            target = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return (target*B)%mod;
}
