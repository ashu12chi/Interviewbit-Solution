vector<vector<int> > Solution::fourSum(vector<int> &ar, int sum) {
    sort(ar.begin(),ar.end());
    int n = ar.size();
    vector<vector<int>> ans;
    unordered_map<int,vector<pair<int,int>>> ump;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ump[ar[i] + ar[j]].push_back(make_pair(i,j));
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int temp = sum - ar[i] - ar[j];
            if(ump.find(temp)!=ump.end())
            {
                for(int i=0;i<ump[temp].size();i++)
                {
                    int x = ump[temp][i].first;
                    int y = ump[temp][i].second;
                    if(x!=i && x!=j && y!=i && y!=j)
                    {
                        vector<int> ashu;
                        ashu.push_back(ar[i]);
                        ashu.push_back(ar[j]);
                        ashu.push_back(ar[x]);
                        ashu.push_back(ar[y]);
                        sort(ashu.begin(),ashu.end());
                        ans.push_back(ashu);
                    }
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
