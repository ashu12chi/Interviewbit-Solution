pair<int,int> isEmpty(vector<vector<char>>& ar)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(ar[i][j] == '.')
                return {i,j};
        }
    }
    return {-1,-1};
}
bool isSafe(vector<vector<char>>& ar,int row,int col,char num)
{
    for(int i=0;i<9;i++)
    {
        if(ar[i][col] == num)
            return false;
        if(ar[row][i] == num)
            return false;
    }
    int row1 = row-row%3;
    int col1 = col-col%3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(ar[row1+i][col1+j] == num)
                return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>>& ar)
{
    pair<int,int> p = isEmpty(ar);
    if(p.first == -1)
        return true;
    for(int i=1;i<=9;i++)
    {
        if(isSafe(ar,p.first,p.second,(char)('0'+i)))
        {
            ar[p.first][p.second] = (char)('0'+i);
            if(solve(ar))
                return true;
            ar[p.first][p.second] = '.';
        }
    }
    return false;
}
void Solution::solveSudoku(vector<vector<char>> &ar) {
    solve(ar);
}
