vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<int,int> ump;
    ump[0] = -1;
    int sum = 0;
    int start = -1;
    int end = -1;
    int len = 0;
    for(int i=0;i<A.size();i++)
    {
        sum += A[i];
        if(ump.find(sum) != ump.end())
        {
            int len1 = i-ump[sum];
            if(len1>len)
            {
                len = len1;
                start = ump[sum];
                end = i;
            }
        }
        else
            ump[sum] = i;
    }
    vector<int> ans;
    for(int i=start+1;i<=end;i++)
        ans.push_back(A[i]);
    return ans;
}
