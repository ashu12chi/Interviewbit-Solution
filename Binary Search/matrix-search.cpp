int Solution::searchMatrix(vector<vector<int> > &ar, int b) {
    int n = ar.size();
    int m = ar[0].size();
    for(int i=0;i<n;i++)
    {
        if(ar[i][0]<=b && ar[i][m-1]>=b)
        {
            if(binary_search(ar[i].begin(),ar[i].end(),b))
                return 1;
        }
    }
    return 0;
}
