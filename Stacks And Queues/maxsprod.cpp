#define mod 1000000007
int Solution::maxSpecialProduct(vector<int> &A) {
    int n = A.size();
    long long left[n];
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && A[s.top()] <= A[i])
            s.pop();
        if(!s.empty())
        {
            left[i] = s.top();
        }
        else
            left[i] = 0;
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    long long right[n];
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && A[s.top()] <= A[i])
            s.pop();
        if(!s.empty())
        {
            right[i] = s.top();
        }
        else
            right[i] = 0;
        s.push(i);
    }
    long long ans = 0ll;
    for(int i=0;i<n;i++)
    {
        ans = max(ans,left[i]*right[i]);
    }
    return ans%mod;
}
