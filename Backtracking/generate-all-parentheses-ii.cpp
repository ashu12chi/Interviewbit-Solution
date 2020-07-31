set<string> ans;
void solve(int count1,int count2,int n,string& ashu)
{
    if(count1 + count2 == 2*n)
    {
        ans.insert(ashu);
        return;
    }
    if(count1<n)
    {
        ashu += '(';
        solve(count1+1,count2,n,ashu);
        ashu.pop_back();
    }
    if(count2<count1)
    {
        ashu += ')';
        solve(count1,count2+1,n,ashu);
        ashu.pop_back();
    }
}
vector<string> Solution::generateParenthesis(int n) {
    ans.clear();
    string ashu = "";
    solve(0,0,n,ashu);
    vector<string> v(ans.begin(),ans.end());
    return v;
}
