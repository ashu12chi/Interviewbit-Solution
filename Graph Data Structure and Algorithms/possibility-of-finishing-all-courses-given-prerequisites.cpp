bool isCyclic(int u,bool vis[],bool rec_stack[],vector<int> adj[])
{
    vis[u] = true;
    rec_stack[u] = true;
    for(int x : adj[u])
    {
        if(!vis[x])
        {
            if(isCyclic(x,vis,rec_stack,adj))
                return true;
        }
        else if(rec_stack[x])
            return true;
    }
    rec_stack[u] = false;
    return false;
}
int Solution::solve(int n, vector<int> &B, vector<int> &C) {
    vector<int> adj[n+1];
    for(int i=0;i<B.size();i++)
    {
        adj[C[i]].push_back(B[i]);
    }
    bool vis[n+1];
    bool rec_stack[n+1];
    for(int i=0;i<=n;i++)
    {
        vis[i] = rec_stack[i] = false;
    }
    for(int i=1;i<=n;i++)
    {
        if(isCyclic(i,vis,rec_stack,adj))
            return 0;
    }
    return 1;
}
