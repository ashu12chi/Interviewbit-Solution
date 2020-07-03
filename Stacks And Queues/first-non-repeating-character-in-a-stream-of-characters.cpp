string Solution::solve(string s) {
    int hash[26] = {0};
    int n = s.size();
    string ans = "";
    stack<char> st;
    for(int i=0;i<n;i++)
    {
        hash[s[i]]++;
        st.push(s[i]);
        while(!st.empty() && hash[s[i]] != 1)
            st.pop();
        if(st.empty())
            ans += '#';
        else
            ans += st.top();
    }
    return ans;
}
