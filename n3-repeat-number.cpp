int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int count1 = 0;
    int count2 = 0;
    int first = INT_MAX;
    int second = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(first == A[i])
            count1++;
        else if(second == A[i])
            count2++;
        else if(count1 == 0)
        {
            first = A[i];
            count1++;
        }
        else if(count2 == 0)
        {
            second = A[i];
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for(int i=0;i<n;i++)
    {
        if(first == A[i])
            count1++;
        if(second == A[i])
            count2++;
    }
    if(count1 > n/3)
        return first;
    if(count2 > n/3)
        return second;
    return -1;
}
