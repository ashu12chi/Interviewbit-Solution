#define ll long long
int Solution::books(vector<int> &A, int B) {
    if(A.size() < B)
        return -1;
    ll low = 0ll;
    ll high = 0ll;
    for(int i=0;i<A.size();i++)
    {
        low = max(low,(ll)A[i]);
        high += A[i];
    }
    ll target = -1ll;
    while(low <= high)
    {
        ll mid = (low+high)/2;
        ll num = 1ll;
        ll sum = 0ll;
        for(int i=0;i<A.size();i++)
        {
            if(sum+A[i]>mid)
            {
                sum = A[i];
                num++;
            }
            else
                sum += A[i];
        }
        if(num <= B)
        {
            target = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return target;
}
