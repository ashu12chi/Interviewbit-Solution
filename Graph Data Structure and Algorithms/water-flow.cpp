void bfs(queue<pair<int,int>>& q,vector<vector<bool>>& vis,vector<vector<int>>& A,int n,int m)
{
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x = dx[i]+p.first;
            int y = dy[i]+p.second;
            if(x>=0 && y>=0 && x<n && y<m && vis[x][y] == false && A[p.first][p.second] <= A[x][y])
            {
                q.push({x,y});
                vis[x][y] = true;
            }
        }
    }
}
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0)
        return 0;
    int m = A[0].size();
    vector<vector<bool>> red(n,vector<bool>(m,false));
    vector<vector<bool>> blue(n,vector<bool>(m,false));
    queue<pair<int,int>> q1,q2;
    for(int i=0;i<n;i++)
    {
        q1.push({i,0});
        red[i][0] = true;
        q2.push({i,m-1});
        blue[i][m-1] = true;
    }
    for(int i=0;i<m;i++)
    {
        q1.push({0,i});
        red[0][i] = true;
        q2.push({n-1,i});
        blue[n-1][i] = true;
    }
    bfs(q1,red,A,n,m);
    bfs(q2,blue,A,n,m);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(red[i][j] && blue[i][j])
                ans++;
        }
    }
    return ans;
}
