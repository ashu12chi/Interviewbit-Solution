int Solution::majorityElement(const vector<int> &A) {
    vector B=A;
    sort(B.begin(), B.end());
    return B[B.size()/2];
}
