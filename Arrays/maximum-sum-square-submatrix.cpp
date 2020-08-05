int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size();
    int prefix[n][n];
    prefix[0][0] = A[0][0];
    for(int i=1;i<n;i++)
        prefix[0][i] = A[0][i] + prefix[0][i-1];
    for(int i=1;i<n;i++)
        prefix[i][0] = A[i][0] + prefix[i-1][0];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            prefix[i][j] = A[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    int ans = INT_MIN;
    for(int i=0;i+B-1<n;i++)
    {
        for(int j=0;j+B-1<n;j++)
        {
            int val = prefix[i+B-1][j+B-1];
            if(i>0)
                val -= prefix[i-1][j+B-1];
            if(j>0)
                val -= prefix[i+B-1][j-1];
            if(i>0 && j>0)
                val += prefix[i-1][j-1];
            ans = max(ans,val);
        }
    }
    return ans;
}
