int Solution::lis(const vector<int> &ar) {
    int n = ar.size();
    if(n == 0)
        return 0;
    int lis[n];
    for(int i=0;i<n;i++)
    {
        lis[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(ar[j] < ar[i] && lis[i] < lis[j]+1)
                lis[i] = lis[j] + 1;
        }
    }
    return *max_element(lis,lis+n);
}
