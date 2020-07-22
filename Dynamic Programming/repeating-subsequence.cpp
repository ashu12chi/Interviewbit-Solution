int Solution::anytwo(string A) {
    map<string,pair<int,int>> m;
    for(int i=1;i<A.size();++i)
    {
        for(int j=0;j<i;++j)
        {
            string s="";
            s=s+A[j]+A[i];
            if(m.find(s) != m.end())
            {
                if(m[s].first!=j && m[s].second!=i )
                    return 1;
            }
            else 
            {
                m[s].first=j;
                m[s].second=i;
            }
        }
    }
    return 0;
}
