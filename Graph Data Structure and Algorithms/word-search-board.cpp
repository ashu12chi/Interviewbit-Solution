int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m;
bool dfs(int x,int y,vector<string>&A,string& B,int ind)
{
    if(ind == B.size())
        return 1;
    if(x<0 || y<0 || x>=n || y >= m || A[x][y] != B[ind])
        return false;
    for(int i=0;i<4;i++)
    {
        if(dfs(x+dx[i],y+dy[i],A,B,ind+1))
            return true;
    }
    return false;
}
int Solution::exist(vector<string> &A, string B) {
    if(B.size() == 0)
        return 1;
    n = A.size();
    if(n == 0)
        return 0;
    m = A[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j] == B[0])
            {
                if(dfs(i,j,A,B,0))
                    return 1;
            }
        }
    }
    return 0;
}
