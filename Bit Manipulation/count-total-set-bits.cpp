#define ll long long
#define mod 1000000007
int Solution::solve(int A) {
    if(A <= 1)
        return A;
    ll n = log2(A);
    ll m = pow(2,n-1);
    int next_A = A - 2*m;
    ll ans1 = (n*m)%mod;
    ans1 = (ans1+1)%mod;
    ans1 = (ans1+next_A)%mod;
    ll ans2 = solve(next_A);
    ll ans3 = (ans1+ans2)%mod;
    return ans3;
}
