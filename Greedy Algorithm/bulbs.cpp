int Solution::bulbs(vector<int> &A) {
    int ans = 0;
    int count = 0;
    for(int i=0;i<A.size();i++)
    {
        int state = A[i]+count;
        if(state == 1)
        {
            // do nothing
        }
        else
        {
            ans++;
            count = (count+1)%2;
        }
    }
    return ans;
}
