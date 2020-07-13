void Solution::solve(vector<vector<char> > &A) {
    int n = A.size();
    if(n == 0)
        return;
    int m = A[0].size();
    int vis[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            vis[i][j] = 0;
    }
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j] == 'O' && vis[i][j] == 0)
            {
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j] = 1;
                bool flag = true;
                vector<pair<int,int>> v;
                v.push_back({i,j});
                while(!q.empty())
                {
                    auto p = q.front();
                    q.pop();
                    for(int k=0;k<4;k++)
                    {
                        int x = p.first+dx[k];
                        int y = p.second+dy[k];
                        if(x>=0 && y>=0 && x<n && y<m)
                        {
                            if(vis[x][y] == 0 && A[x][y] == 'O')
                            {
                                q.push({x,y});
                                vis[x][y] = 1;
                                v.push_back({x,y});
                            }
                        }
                        else
                        {
                            flag = false;
                        }
                    }
                }
                if(flag)
                {
                    for(int i=0;i<v.size();i++)
                    {
                        A[v[i].first][v[i].second] = 'X';
                    }
                }
            }
        }
    }
}
