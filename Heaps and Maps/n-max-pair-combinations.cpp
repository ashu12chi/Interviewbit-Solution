vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int n = A.size();
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
        pq.push(A[i]+B[n-1]);
    for(int i=0;i<n-1;i++)
        pq.push(A[n-1]+B[i]);
    for(int i=0;i<n;i++)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
