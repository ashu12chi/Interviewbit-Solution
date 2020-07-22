bool solve(const string& s,const string& p,int i,int j,vector<vector<int>>& dp)
{
    //cout << i << " " << j << "\n";
    if(i == s.size() && j == p.size())
        return true;
    if(j == p.size())
        return false;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == s.size())
    {
        if(j+1<p.size() && p[j+1] == '*')
            return dp[i][j] = solve(s,p,i,j+2,dp);
        return dp[i][j] = false;
    }
    if(p[j] == '.' && j+1<p.size() && p[j+1] == '*')
        return dp[i][j] = solve(s,p,i+1,j+2,dp) | solve(s,p,i+1,j,dp) | solve(s,p,i,j+2,dp);
    if(p[j] == '.')
        return dp[i][j] = solve(s,p,i+1,j+1,dp);
    if(p[j] == s[i] && j+1<p.size() && p[j+1] == '*')
        return dp[i][j] = solve(s,p,i+1,j+2,dp) | solve(s,p,i+1,j,dp) | solve(s,p,i,j+2,dp);
    if(p[j] == s[i])
        return dp[i][j] = solve(s,p,i+1,j+1,dp);
    if(j+1 < p.size() && p[j+1] == '*')
        return dp[i][j] = solve(s,p,i,j+2,dp);
    return dp[i][j] = false;
}
int Solution::isMatch(const string A, const string B) {
    int n = A.size();
    int m = B.size();
    vector<vector<int>> dp(n+10,vector<int>(m+10,-1));
    return solve(A,B,0,0,dp);
}
