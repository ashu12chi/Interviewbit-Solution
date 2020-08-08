int dfs(vector<int> adj[],int ind,bool vis[],bool stack[],int par)
{
    vis[ind] = true;
    stack[ind] = true;
    for(int x : adj[ind])
    {
        if(x != par)
        {
            if(vis[x] == false)
            {
                if(dfs(adj,x,vis,stack,ind))
                    return 1;
            }
            else if(stack[x])
                return 1;
        }
    }
    stack[ind] = false;
    return 0;
}
int Solution::solve(int n, vector<vector<int> > &B) {
    vector<int> adj[n+1];
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
    }
    bool vis[n+1];
    bool stack[n+1];
    for(int i=1;i<=n;i++)
    {
        vis[i] = false;
        stack[i] = false;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i] == false)
        {
            if(dfs(adj,i,vis,stack,-1))
                return 1;
        }
    }
    return 0;
}
