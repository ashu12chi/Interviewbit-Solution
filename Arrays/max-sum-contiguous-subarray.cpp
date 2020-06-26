int Solution::maxSubArray(const vector<int> &ar) {
    int curr_sum = 0;
    int max_sum = INT_MIN;
    int n = ar.size();
    for(int i=0;i<n;i++)
    {
        curr_sum += ar[i];
        max_sum = max(max_sum,curr_sum);
        if(curr_sum<0)
            curr_sum = 0;
    }
    return max_sum;
}
