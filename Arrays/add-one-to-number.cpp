vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size();
    int carry = 1;
    for(int i=n-1;i>=0;i--)
    {
        if(carry == 0)
            break;
        int temp = A[i] + carry;
        carry = temp/10;
        A[i] = temp%10;
    }
    vector<int> ans;
    if(carry!=0)
    {
        ans.push_back(carry);
        for(int i=0;i<n;i++)
            ans.push_back(A[i]);
    }
    else
    {
        int i = 0;
        while(A[i] == 0)
            i++;
        while(i<n)
        {
            ans.push_back(A[i]);
            i++;
        }
    }
    return ans;
}
