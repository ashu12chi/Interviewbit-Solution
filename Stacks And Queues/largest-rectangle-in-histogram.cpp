#define ll long long
int Solution::largestRectangleArea(vector<int> &ar) {
    int n = ar.size();
    stack<ll> s;
        int i = 0;
        ll ans = 0ll;
        s.push(-1);
        while(i<n)
        {
            if(s.top() == -1 || ar[i] >= ar[s.top()])
                s.push(i++);
            else
            {
                ll top = s.top();
                s.pop();
                ll temp = ar[top]*(i-s.top()-1);
                ans = max(ans,temp);
            }
        }
        while(s.top()!=-1)
        {
            ll top = s.top();
            s.pop();
            ll temp = ar[top]*(i-s.top()-1);
            ans = max(ans,temp);
        }
    return ans;
}
