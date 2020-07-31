string Solution::getPermutation(int n, int k) {
    vector<int> v(n);
    for(int i=1;i<=n;i++)
        v[i-1] = i;
    for(int i=0;i<k-1;i++)
    {
        next_permutation(v.begin(),v.end());
    }
    string ans = "";
    for(int i=0;i<n;i++)
    {
        int temp = v[i];
        string ans1 = "";
        while(temp)
        {
            ans1 += (char)('0'+temp%10);
            temp /= 10;
        }
        reverse(ans1.begin(),ans1.end());
        ans += ans1;
    }
    return ans;
}
