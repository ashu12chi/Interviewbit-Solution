int Solution::solve(vector<vector<int> > &ar) {
    int n = ar.size();
    if(n == 0)
        return 0;
    int m = ar[0].size();
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int count = 0;
        for(int j=0;j<m;j++)
        {
            if(ar[i][j])
                count++;
        }
        ans = max(ans,count);
    }
    for(int i=0;i<n;i++)
    {
        int ar1[m];
        for(int j=0;j<m;j++)
            ar1[j] = ar[i][j];
        for(int k=i+1;k<n;k++)
        {
            int count = 0;
            for(int j=0;j<m;j++)
            {
                if(ar[k][j] && ar1[j])
                {
                    ar1[j]++;
                    count += k-i+1;
                }
                else
                    ar1[j] = 0;
            }
            ans = max(ans,count);
        }
    }
    return ans;
}
