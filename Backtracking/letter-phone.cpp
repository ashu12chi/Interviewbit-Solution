set<string> ans;
int n;
string has[10];
void solve(string& str,int i,string& ashu)
{
    if(i == n)
    {
        ans.insert(ashu);
        return;
    }
        for(int j=0;j<has[str[i]-'0'].size();j++)
        {
            ashu += has[str[i]-'0'][j];
            solve(str,i+1,ashu);
            ashu.pop_back();
        }
}
vector<string> Solution::letterCombinations(string str) {
    ans.clear();
    n = str.size();
    has[0] = "0";
    has[1] = "1";
    has[2] = "abc";
    has[3] = "def";
    has[4] = "ghi";
    has[5] = "jkl";
    has[6] = "mno";
    has[7] = "pqrs";
    has[8] = "tuv";
    has[9] = "wxyz";
    string ashu = "";
    solve(str,0,ashu);
    vector<string> v(ans.begin(),ans.end());
    return v;
}
