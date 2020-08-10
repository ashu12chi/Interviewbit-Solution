int Solution::titleToNumber(string s) {
    int n = s.size();
    long long ans = 0ll;
    long long val = 1ll;
    for(int i=n-1;i>=0;i--)
    {
        ans += val*(s[i]-'A'+1);
        val *= 26;
    }
    return ans;
}
