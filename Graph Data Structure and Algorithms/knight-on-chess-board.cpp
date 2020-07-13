int Solution::knight(int A, int B, int C, int D, int E, int F) {
    C--;
    D--;
    E--;
    F--;
    bool vis[A][B];
    for(int i=0;i<A;i++)
    {
        for(int j=0;j<B;j++)
            vis[i][j] = false;
    }
    vis[C][D] = true;
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{C,D}});
    int dx[] = {2,1,-1,-2,-2,-1,1,2};
    int dy[] = {1,2,2,1,-1,-2,-2,-1};
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        if(p.second.first == E && p.second.second == F)
            return p.first;
        for(int i=0;i<8;i++)
        {
            int x = p.second.first+dx[i];
            int y = p.second.second+dy[i];
            if(x>=0 && y>=0 && x<A && y<B && vis[x][y] == false)
            {
                vis[x][y] = true;
                q.push({p.first+1,{x,y}});
            }
        }
    }
    return -1;
}
