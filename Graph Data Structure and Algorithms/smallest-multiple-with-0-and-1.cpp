string Solution::multiple(int n) {
    if(n <= 1)
        return n;
    bool vis[n];
    memset(vis,false,sizeof(vis));
    int parent[n],digit[n];
    vis[1] = true;
    parent[1] = -1;
    digit[1] = 1;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        if(p == 0)
            break;
        int mod = (p*10)%n;
        if(!vis[mod])
        {
            vis[mod] = true;
            parent[mod] = p;
            digit[mod] = 0;
            q.push(mod);
        }
        mod = (p*10+1)%n;
        
    }
}
