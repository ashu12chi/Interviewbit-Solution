set<vector<int>> ans;
int n;
void solve(vector<int>& ar,int index,int total,int sum,vector<int>& ashu)
{
    if(total == sum)
    {
        ans.insert(ashu);
        return;
    }
    if(total>sum)
        return;
    for(int i=index;i<n;i++)
    {
        ashu.push_back(ar[i]);
        solve(ar,i+1,total+ar[i],sum,ashu);
        ashu.pop_back();
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &ar, int sum) {
   n = ar.size();
   ans.clear();
   vector<int> ashu;
   sort(ar.begin(),ar.end());
   solve(ar,0,0,sum,ashu);
   vector<vector<int>> v(ans.begin(),ans.end());
   return v;
}
