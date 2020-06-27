vector<int> Solution::findPerm(const string A, int n) {
    int l = 1;
    int r = n;
    vector<int> ans;
    for(int i=0;i<n-1;i++)
    {
        if(A[i] == 'I')
        {
            ans.push_back(l++);
        }
        else
        {
            ans.push_back(r--);
        }
    }
    ans.push_back(l);
    return ans;
}
