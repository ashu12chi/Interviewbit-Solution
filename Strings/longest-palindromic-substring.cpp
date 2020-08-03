string Solution::longestPalindrome(string str) {
    int n = str.size();
    bool dp[n][n];
    memset(dp,false,sizeof(dp));
    for(int i=0;i<n;i++)
        dp[i][i] = true;
    int ind = 0;
    int len = 1;
    for(int i=1;i<n;i++)
    {
        if(str[i]==str[i-1])
        {
            dp[i-1][i] = true;
            if(len<2)
            {
                ind = i-1;
                len = 2;
            }
        }
    }
    for(int l=3;l<=n;l++)
    {
        for(int i=0;i<n+1-l;i++)
        {
            int j = i+l-1;
            if(dp[i+1][j-1] && str[i] == str[j])
            {
                dp[i][j] = true;
                if(len < l)
                {
                    len = l;
                    ind = i;
                }
            }
        }
    }
    return str.substr(ind,len);
}
