int Solution::searchInsert(vector<int> &A, int B) {
    return (lower_bound(A.begin(),A.end(),B)-A.begin());
}
