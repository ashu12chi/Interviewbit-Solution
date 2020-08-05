int Solution::solve(vector<int> &A) {
    int n = A.size();
    int sum = 0;
    unordered_map<int,int> ump;
    ump[0] = -1;
    int ans = 0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i] == 1)
            sum++;
        else
            sum--;
        if(ump.find(sum-1) != ump.end())
        {
            ans = max(ans,i-ump[sum-1]);
        }
        if(ump.find(sum) == ump.end())
            ump[sum] = i;
    }
    return ans;
}
