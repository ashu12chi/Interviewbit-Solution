int Solution::solve(string A, string B, vector<string> &C) {
    unordered_set<string> s;
    for(int i=0;i<C.size();i++)
    {
        s.insert(C[i]);
    }
    s.insert(A);
    s.insert(B);
    queue<pair<int,string>> q;
    q.push({1,A});
    s.erase(s.find(A));
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        if(p.second == B)
            return p.first;
        for(int i=0;i<p.second.size();i++)
        {
            for(int j=0;j<26;j++)
            {
                string temp = p.second;
                temp[i] = (char)('a'+j);
                if(s.find(temp) != s.end())
                {
                    s.erase(temp);
                    q.push({p.first+1,temp});
                }
            }
        }
    }
    return 0;
}
