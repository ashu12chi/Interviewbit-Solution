int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int low = 0;
    int high = n-1;
    int pivot = -1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(A[mid] >= A[0])
        {
            pivot = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
   // cout << pivot << " ";
    if(binary_search(A.begin(),A.begin()+pivot+1,B))
    {
        int it = lower_bound(A.begin(),A.begin()+pivot+1,B) - A.begin();
        return it;
    }
    if(binary_search(A.begin()+pivot+1,A.end(),B))
    {
        int it = lower_bound(A.begin()+pivot+1,A.end(),B) - A.begin();
        return it;
    }
    return -1;
}
