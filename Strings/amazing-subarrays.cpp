#define ll long long
#define mod 10003
int Solution::solve(string A) {
    ll n = A.size();
    ll ans = 0ll;
    for(int i=0;i<n;i++)
    {
        if(A[i] == 'A' || A[i] == 'E' || A[i] == 'O' || A[i] == 'I' || A[i] == 'U' || A[i] == 'a' || A[i] == 'o' || A[i] == 'e' || A[i] == 'i' || A[i] == 'u')
        {
            ans = (ans + (n-i))%mod;
        }
    }
    return ans;
}
