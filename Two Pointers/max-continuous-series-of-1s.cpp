vector<int> Solution::maxone(vector<int> &ar, int m) {
    int n = ar.size();
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        if(ar[i] == 0)
            v.push_back(i);
    }
    if(v.size()<=m)
    {
        vector<int> ans(n);
        for(int i=0;i<n;i++)
            ans[i] = i;
        return ans;
    }
    int l = 0;
    int r = v[m]-1;
    v.push_back(n);
    for(int i=m+1;i<v.size();i++)
    {
        int l1 = v[i-m-1]+1;
        int r1 = v[i]-1;
        if(r1-l1>r-l)
        {
            r = r1;
            l = l1;
        }
    }
    vector<int> ans;
    for(int i=l;i<=r;i++)
        ans.push_back(i);
    return ans;
}
