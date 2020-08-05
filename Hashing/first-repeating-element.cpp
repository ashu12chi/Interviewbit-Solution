int Solution::solve(vector<int> &A) {
    unordered_map<int,int> ump;
    for(int i=0;i<A.size();i++)
    {
        ump[A[i]]++;
    }
    for(int i=0;i<A.size();i++)
    {
        if(ump[A[i]]>1)
            return A[i];
    }
    return -1;
}
