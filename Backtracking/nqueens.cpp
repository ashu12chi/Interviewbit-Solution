vector<vector<string>> ans;
bool isSafe(vector<string>& v,int row,int col,int n)
{
    for(int i=0;i<col;i++)
    {
        if(v[row][i] == 'Q')
            return false;
    }
    int i = row;
    int j = col;
    while(i>=0 && j>=0)
    {
        if(v[i][j] == 'Q')
            return false;
        i--;
        j--;
    }
    i = row;
    j = col;
    while(i<n && j>=0)
    {
        if(v[i][j] == 'Q')
            return false;
        i++;
        j--;
    }
    return true;
}
void solve(vector<string>& v,int col,int n)
{
    if(col == n)
    {
        ans.push_back(v);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(v,i,col,n))
        {
            v[i][col] = 'Q';
            solve(v,col+1,n);
            v[i][col] = '.';
        }
    }
}
vector<vector<string> > Solution::solveNQueens(int n) {
    ans.clear();
    string s = "";
    for(int i=0;i<n;i++)
        s += '.';
    vector<string> v(n,s);
    solve(v,0,n);
    return ans;
}
