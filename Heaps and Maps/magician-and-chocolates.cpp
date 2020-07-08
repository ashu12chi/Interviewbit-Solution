int Solution::nchoc(int A, vector<int> &B) {
    long long ans = 0;
    priority_queue<long long> pq;
    for(int i=0;i<B.size();i++)
        pq.push(B[i]);
    while(A-- && !pq.empty())
    {
        long long temp = pq.top();
        ans = (ans+temp)%(1000000007);
        pq.pop();
        pq.push(temp/2);
    }
    return ans;
}
