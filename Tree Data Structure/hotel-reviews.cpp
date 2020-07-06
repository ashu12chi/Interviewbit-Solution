bool comp(pair<int,int> p,pair<int,int> q)
{
    if(p.first == q.first)
        return p.second < q.second;
    return p.first > q.first;
}
vector<int> Solution::solve(string A, vector<string> &B) {
    unordered_set<string> u;
    string temp = "";
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!='_')
            temp += A[i];
        else
        {
            u.insert(temp);
            temp = "";
        }
    }
    u.insert(temp);
    //for(auto it=u.begin();it!=u.end();it++)
      //  cout << *it << " ";
    vector<pair<int,int>> v;
    for(int i=0;i<B.size();i++)
    {
        string temp = "";
        int count = 0;
        for(int j=0;j<B[i].size();j++)
        {
            if(B[i][j]!='_')
                temp += B[i][j];
            else
            {
                if(u.find(temp)!=u.end())
                {
                    count++;
                }
                temp = "";
            }
        }
        if(u.find(temp)!=u.end())
        {
            count++;
        }
        v.push_back(make_pair(count,i));
    }
    sort(v.begin(),v.end(),comp);
    vector<int> ans;
    for(int i=0;i<v.size();i++)
        ans.push_back(v[i].second);
    return ans;
}
