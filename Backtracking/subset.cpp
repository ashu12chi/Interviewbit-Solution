vector<vector<int>> ans;
int n;
void solve(vector<int>& ar,vector<int>& sol,int index)
{
    ans.push_back(sol);
    for(int i=index;i<n;i++)
    {
        sol.push_back(ar[i]);
        solve(ar,sol,i+1);
        sol.pop_back();
    }
}
vector<vector<int> > Solution::subsets(vector<int> &ar) {
    sort(ar.begin(),ar.end());
    n = ar.size();
    vector<int> sol;
    solve(ar,sol,0);
    return ans;
}
