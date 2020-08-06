int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int curr = 0;
    int count = 0;
    while(curr < n)
    {
        int next = curr+B-1;
        int ind = next;
        int prev = curr-B+1;
        if(prev<0)
            prev = 0;
        while(ind>=prev)
        {
            if(A[ind])
                break;
            ind--;
        }
        if(ind >= prev)
        {
            count++;
            curr = ind+B;
        }
        else
            return -1;
    }
    return count;
}
