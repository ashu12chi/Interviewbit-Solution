string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    bool safe[A+1][B+1];
    bool vis[A+1][B+1];
    for(int i=0;i<=A;i++)
    {
        for(int j=0;j<=B;j++)
        {
            safe[i][j] = true;
            vis[i][j] = false;
        }
    }
    for(int i=0;i<=A;i++)
    {
        for(int j=0;j<=B;j++)
        {
            for(int k=0;k<C;k++)
            {
                int x1 = E[k];
                int y1 = F[k];
                int dist = (x1-i)*(x1-i) + (y1-j)*(y1-j);
                if(dist <= D*D)
                {
                    safe[i][j] = false;
                    break;
                }
            }
        }
    }
    if(!safe[0][0] || !safe[A][B])
        return "NO";
    queue<pair<int,int>> q;
    q.push({0,0});
    int dx[] = {1,1,1,0,0,-1,-1,-1};
    int dy[] = {-1,0,1,-1,1,-1,0,1};
    vis[0][0] = true;
    while(!q.empty())
    {
        auto p = q.front();
        if(p.first == A && p.second == B)
            return "YES";
        q.pop();
        for(int i=0;i<8;i++)
        {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if(x>=0 && y>=0 && x<=A && y<=B && !vis[x][y] && safe[x][y])
            {
                vis[x][y] = true;
                q.push({x,y});
            }
        }
    }
    return "NO";
}
