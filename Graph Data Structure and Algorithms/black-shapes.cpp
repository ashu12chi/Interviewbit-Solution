int Solution::black(vector<string> &A) {
    int n = A.size();
    if(n == 0)
        return 0;
    int m = A[0].size();
    bool vis[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            vis[i][j] = true;
    }
    int ans = 0;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j] != 'X' || vis[i][j])
                continue;
            queue<pair<int,int>> q;
            q.push({i,j});
            vis[i][j] = true;
            ans++;
            while(!q.empty())
            {
                auto p = q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int x = p.first+dx[i];
                    int y = p.second+dy[i];
                    if(x>=0 && y>=0 && x<n && y<m && A[i][j] == 'X' && !vis[x][y])
                    {
                        vis[x][y] = true;
                        q.push({x,y});
                    }
                }
            }
        }
    }
    return ans;
}
