int A;
int dfs(vector<int> adj[],int ind,bool vis[])
{
    vis[ind] = true;
    for(int x : adj[ind])
    {
        if(x == A)
            return 1;
        if(vis[x] == false)
        {
            if(dfs(adj,x,vis))
                return 1;
        }
    }
    return 0;
}
int Solution::solve(int n, vector<vector<int> > &B) {
    A = n;
    vector<int> adj[n+1];
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
    }
    bool vis[n+1];
    for(int i=1;i<=n;i++)
    {
        vis[i] = false;
    }
    if(dfs(adj,1,vis))
        return 1;
    return 0;
}
