vector<int> Solution::solve(int p1, int p2, int p3, int k) {
    int ar[] = {p1,p2,p3};
    sort(ar,ar+3);
    p1 = ar[0],p2=ar[1],p3=ar[2];
    queue<int> q;
    vector<int> v;
    q.push(p1);
    q.push(p2);
    q.push(p3);
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        v.push_back(p);
        if(v.size() == k)
            return v;
        q.push()
    }
}
