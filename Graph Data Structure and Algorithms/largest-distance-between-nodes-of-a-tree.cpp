void dfs(vector<int> adj[],int u,int par,int height,int depth[])
{
    depth[u] = height;
    for(int x : adj[u])
    {
        if(x != par)
        {
            dfs(adj,x,u,height+1,depth);
        }
    }
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> adj[n];
    for(int i=0;i<n;i++)
    {
        if(A[i] == -1)
            continue;
        adj[A[i]].push_back(i);
        adj[i].push_back(A[i]);
    }
    int depth[n];
    dfs(adj,0,-1,0,depth);
    int u = 0;
    for(int i=1;i<n;i++)
    {
        if(depth[u] < depth[i])
            u = i;
    }
    dfs(adj,u,-1,0,depth);
    u = 0;
    for(int i=1;i<n;i++)
    {
        if(depth[u] < depth[i])
            u = i;
    }
    return depth[u];
}
