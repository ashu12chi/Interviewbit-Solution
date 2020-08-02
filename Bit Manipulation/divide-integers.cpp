#define ll long long
int Solution::divide(int a,int b) {
    ll A = a;
    ll B = b;
    if(B == 0)
        return INT_MAX;
    if(A == 0)  
        return 0;
    ll sign = ((A<0)^(B<0))?-1:1;
    A = abs(A);
    B = abs(B);
    ll quotient = 0ll;
    ll rem = 0ll;
    for(int i=31;i>=0;i--)
    {
        if(rem + (B << i) <= A)
        {
            rem += B<<i;
            quotient |= 1ll<<i;
        }
    }
    return min(sign*quotient,(ll)INT_MAX);
}
