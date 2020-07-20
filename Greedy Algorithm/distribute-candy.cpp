int Solution::candy(vector<int> &A) {
    int n = A.size();
    int candies[n];
    memset(candies,0,sizeof(candies));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<n;i++)
    {
        pq.push({A[i],i});   
    }
    int ans = 0;
    while(!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int i = p.second;
        int maxe = 0;
        if(i>0 && A[i] > A[i-1])
            maxe = max(candies[i-1],maxe);
        if(i<n-1 && A[i] > A[i+1])
            maxe = max(candies[i+1],maxe);
        candies[i] = maxe+1;
        ans += candies[i];
    }
    return ans;
}
