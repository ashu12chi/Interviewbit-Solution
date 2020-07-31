vector<vector<int>> ans;
void solve(vector<int>& v,int n,int k,int count,int prev)
{
    if(count == k)
    {
        ans.emplace_back(v);
        return;
    }
    for(int i=prev+1;i<=n;i++)
    {
        v.push_back(i);
        solve(v,n,k,count+1,i);
        v.pop_back();
    }
}g
vector<vector<int> > Solution::combine(int n, int k) {
    ans.clear();
    vector<int> v;
    solve(v,n,k,0,0);
    return ans;
}
