int Solution::canJump(vector<int> &A) {
    int n = A.size();
    int init = n-1;
    for(int i=n-1;i>=0;i--)
    {
        if(A[i] >= init-i)
        {
            init = i;
        }
        if(init == 0)
            return 1;
    }
    return 0;
}
