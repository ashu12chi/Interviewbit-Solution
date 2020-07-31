vector<vector<int>> ans;
void permute1(vector<int>& ar,int l,int r)
{
    if(l == r)
    {
        ans.push_back(ar);
        return;
    }
    for(int i=l;i<=r;i++)
    {
        swap(ar[i],ar[l]);
        permute1(ar,l+1,r);
        swap(ar[i],ar[l]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &ar) {
    int n = ar.size();
    ans.clear();
    permute1(ar,0,n-1);
    return ans;
}
