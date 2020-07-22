int n;
int solve(int dp[],int index,string& str)
{
    if(index == n)
        return 1;
    if(index>n)
        return 0;
    if(dp[index]!=-1)
        return dp[index];
    if(str[index] == '0')
        return dp[index] = 0;
    if(str[index] == '1')
        return dp[index] = solve(dp,index+1,str) + solve(dp,index+2,str);
    if(str[index] == '2')
    {
        if(index == n-1)
            return dp[index] = 1;
        if(str[index+1] <= '6')
            return dp[index] = solve(dp,index+1,str) + solve(dp,index+2,str);
        return dp[index] = dp[index] = solve(dp,index+1,str);
    }
    return solve(dp,index+1,str);
}
int Solution::numDecodings(string str) {
    n = str.size();
    int dp[n+5];
    memset(dp,-1,sizeof(dp));
    return solve(dp,0,str);
}
