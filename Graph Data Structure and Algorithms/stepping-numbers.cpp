vector<int> Solution::stepnum(int A, int B) {
    vector<int> ans;
    if(A<=0)
        ans.push_back(0);
    queue<int> q;
    for(int i=1;i<=9;i++)
        q.push(i);
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        if(p > B)
            break;
        if(p>=A)
            ans.push_back(p);
        int last = p%B;
        if(last>0)
            q.push(p*10+last-1);
        if(last<9)
            q.push(p*10+last+1);
    }
    return ans;
}
