bool comp(vector<int> v1,vector<int> v2)
{
    return v1[2] < v2[2];
}
int find_set(int parent[],int v)
{
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent,parent[v]);
}
void union_set(int parent[],int a,int b)
{
    a = find_set(parent,a);
    b = find_set(parent,b);
    if(a!=b)
        parent[b] = a;
}
int Solution::solve(int n, vector<vector<int> > &B) {
    sort(B.begin(),B.end(),comp);
    int parent[n+1];
    for(int i=1;i<=n;i++)
        parent[i] = i;
    int k = 0;
    int ans = 0;
    for(int i=0;i<B.size();i++)
    {
        int a = B[i][0];
        int b = B[i][1];
        a = find_set(parent,a);
        b = find_set(parent,b);
        if(a == b)
            continue;
        ans += B[i][2];
        k++;
        union_set(parent,a,b);
        if(k == n-1)
            return ans;
    }
    return ans;
}
