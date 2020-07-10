vector<int> Solution::twoSum(const vector<int> &ar, int target) {
    vector<int> ans;
    unordered_map<int,int> ump;
    for(int i=0;i<ar.size();i++)
    {
        int temp = target - ar[i];
        if(ump.find(temp)!=ump.end())
        {
            ans.push_back(ump[temp]);
            ans.push_back(i+1);
            return ans;
        }
        else if(ump.find(ar[i]) == ump.end())
            ump[ar[i]] = i+1;
    }
    return ans;
}
