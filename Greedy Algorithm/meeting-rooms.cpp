int Solution::solve(vector<vector<int>> &time) {
    if(time.size() == 0)
        return 0;
    sort(time.begin(),time.end());
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(time[0][1]);
    for(int i=1;i<time.size();i++)
    {
        if(time[i][0] >= pq.top())
            pq.pop();
        pq.push(time[i][1]);
    }
    return pq.size();
}
