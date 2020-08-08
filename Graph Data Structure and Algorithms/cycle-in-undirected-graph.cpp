int dfs(vector<int> adj[],int ind,bool vis[],int par)
{
    vis[ind] = true;
    for(int x : adj[ind])
    {
        if(x != par)
        {
            if(vis[x] == false)
            {
                if(dfs(adj,x,vis,ind))
                    return 1;
            }
            else
                return 1;
        }
    }
    return 0;
}
int Solution::solve(int n, vector<vector<int> > &B) {
    vector<int> adj[n+1];
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    bool vis[n+1];
    for(int i=1;i<=n;i++)
        vis[i] = false;
    for(int i=1;i<=n;i++)
    {
        if(vis[i] == false)
        {
            if(dfs(adj,i,vis,-1))
                return 1;
        }
    }
    return 0;
}
