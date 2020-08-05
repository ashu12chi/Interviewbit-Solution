vector<int> Solution::intersect(const vector<int> &ar1, const vector<int> &ar2) {
    vector<int> ans;
    int n = ar1.size();
    int m = ar2.size();
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(ar1[i] == ar2[j])
        {
            ans.push_back(ar1[i]);
            i++;
            j++;
        }
        else if(ar1[i]<ar2[j])
            i++;
        else
            j++;
    }
    return ans;
}
