int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int minTotal = 0; 
    int minTotalIndex = -1;
    int total = 0;
    for(int i = 0;i<A.size();i++)
    {
        total += A[i] - B[i];
        if(total < minTotal)
        {
            minTotal = total;
            minTotalIndex = i;
        }
    }
    return total < 0 ? -1 : (minTotalIndex+1);
}
