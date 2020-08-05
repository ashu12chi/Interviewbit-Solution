vector<int> Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> ump;
    int n = A.size();
    for(int i=0;i<n;i++)
        ump[A[i]] = i;
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(B == count)
            return A;
        if(A[i] == n-i)
            ;
        else
        {
            ump[A[i]] = ump[n-i];
            A[ump[n-i]] = A[i];
            ump[n-i] = i;
            A[i] = n-i;
            count++;
        }
    }
    return A;
}
