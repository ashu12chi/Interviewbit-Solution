int Solution::braces(string A) {
    stack<char> s;
    for(int i=0;i<A.size();i++)
    {
        if(A[i] == '(')
            s.push('(');
        else if(A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/')
            s.push('+');
        else if(A[i] == ')')
        {
            if(s.empty() || s.top() == '(')
                return 1;
            if(s.top() == '+')
            {
                s.pop();
                while(!s.empty() && s.top() != '(')
                    s.pop();
            }
            else
                return 1;
        }
    }
    return 0;
}
