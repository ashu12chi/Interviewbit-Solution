#define ll long long
int Solution::sqrt(int A) {
    ll low = 0;
    ll high = A;
    ll target = 0ll;
    while(low <= high)
    {
        ll mid = (low+high)/2;
        if(mid*mid == A)
            return mid;
        else if(mid*mid < A)
        {
            low = mid+1;
            target = mid;
        }
        else
            high = mid-1;
    }
    return target;
}
