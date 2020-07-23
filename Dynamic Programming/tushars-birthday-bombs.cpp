vector<int> Solution::solve(int A, vector<int> &B) {
    vector<int> ans;
    int n = B.size();
    int mine = INT_MAX;
    int mini = -1;
    for(int i=0;i<n;i++)
    {
        if(B[i] < mine)
        {
            mine = B[i];
            mini = i;
        }
    }
    int size = A/mine;
    for(int i=0;i<size;i++)
    {
        ans.push_back(mini);
    }
    int rem = A-mine*size;
    int i = 0;
    int j = 0;
    while(i<mini && rem>0 && j<size)
    {
        if(B[i]-mine >= rem)
        {
            rem -= B[i]-mine;
            ans[j] = i;
            j++;
        }
        else
            i++;
    }
    return ans;
}
