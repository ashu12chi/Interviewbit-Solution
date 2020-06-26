vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    int ar[n];
    for(int i=0;i<n;i++)
        ar[i] = A[i];
    sort(ar,ar+n);
    for(int i=0;i<n;i++)
        ar[i] -= A[i];
    int start = -1;
    int end = -1;
    for(int i=0;i<n;i++)
    {
        if(ar[i] != 0)
        {
            start = i;
            break;
        }
    }
    if(start == -1)
        return {-1};
    for(int i=n-1;i>=0;i--)
    {
        if(ar[i] != 0)
        {
            end = i;
            break;
        }
    }
    return {start,end};
}
