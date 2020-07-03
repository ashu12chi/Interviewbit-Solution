vector<int> Solution::slidingMaximum(const vector<int> &ar, int k) {
    int n = ar.size();
    vector<int> ans;
    deque<int> dq;
    for(int i=0;i<n;i++)
    {
        while(!dq.empty() && i-dq.front() >= k)
            dq.pop_front();
        while(!dq.empty() && ar[dq.front()] <= ar[i])
            dq.pop_front();
        dq.push_back(i);
        if(i>=k-1)
        {
            ans.push_back(ar[dq.front()]);
        }
    }
    return ans;
}
