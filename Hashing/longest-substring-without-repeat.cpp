int Solution::lengthOfLongestSubstring(string A) {
    int n = A.size();
    unordered_map<char,int> ump;
    int ans = 0;
    int start = 0;
    for(int i=0;i<n;i++)
    {
        if(ump.find(A[i]) == ump.end())
            ump[A[i]] = i;
        else if(ump[A[i]] < start)
            ump[A[i]] = i;
        else
        {
            ans = max(ans,i-start);
            start = ump[A[i]]+1;
            ump[A[i]] = i;
        }
    }
    ans = max(ans,n-start);
    return ans;
}
