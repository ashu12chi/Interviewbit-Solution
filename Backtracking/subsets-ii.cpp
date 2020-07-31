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
vector<vector<int> > Solution::subsetsWithDup(vector<int> &ar) {
    sort(ar.begin(),ar.end());
    n = ar.size();
    vector<int> sol;
    ans.clear();
    solve(ar,sol,0);
    set<vector<int>> s;
    unsigned size = ans.size();
    for(unsigned i = 0; i < size; ++i ) s.insert(ans[i] );
    ans.assign( s.begin(), s.end() );
    return ans;
}
