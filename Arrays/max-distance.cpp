int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    int left[n],right[n];
    left[0] = A[0],right[n-1] = A[n-1];
    for(int i=1;i<n;i++)
        left[i] = min(left[i-1],A[i]);
    for(int i=n-2;i>=0;i--)
        right[i] = max(right[i+1],A[i]);
    int i = 0;
    int j = 0;
    int ans = 0;
    while(i<n && j<n)
    {
        if(left[i] <= right[j])
        {
            ans = max(ans,j-i);
            j++;
        }
        else
            i++;
    }
    return ans;
}
