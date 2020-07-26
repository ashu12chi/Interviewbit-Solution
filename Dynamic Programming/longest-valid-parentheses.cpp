int Solution::longestValidParentheses(string A) {
    stack<int> s;
    int n = A.size();
    s.push(-1);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(A[i] == '(')
            s.push(i);
        else
        {
            s.pop();
            if(!s.empty()) 
            {
                ans = max(ans,i-s.top());
            }
            else
                s.push(i);
        }
    }
    return ans;
}
