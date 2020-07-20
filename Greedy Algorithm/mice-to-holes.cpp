×
int Solution::mice(vector<int> &A, vector<int> &B) {
    int ans = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i=0;i<A.size();i++)
        ans = max(ans,abs(A[i]-B[i]));
    return ans;
}
