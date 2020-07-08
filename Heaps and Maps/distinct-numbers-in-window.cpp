vector<int> Solution::dNums(vector<int> &A, int B) {
    if(B > A.size())
        return {};
    unordered_map<int,int> ump;
    for(int i=0;i<B;i++)
        ump[A[i]]++;
    vector<int> ans;
    ans.push_back(ump.size());
    for(int i=B;i<A.size();i++)
    {
        ump[A[i-B]]--;
        if(ump[A[i-B]] == 0)
            ump.erase(A[i-B]);
        ump[A[i]]++;
        ans.push_back(ump.size());
    }
    return ans;
}
