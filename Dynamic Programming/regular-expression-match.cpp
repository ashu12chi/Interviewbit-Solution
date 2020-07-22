#define ll long long
bool solve(const string& A,const string& B,int i,int j,int n,int m,vector<vector<bool>>& dp)
{
    //cout << i << " " << j << "\n";
    if(i == n && j == m)
        return true;
    if(i == n && B[j] == '*')
        return solve(A,B,i,j+1,n,m,dp);
    if(j == m && A[i] == '*')
        return solve(A,B,i+1,j,n,m,dp);
    if(i==n || j==m)
        return false;
    if(dp[i][j] == false)
        return dp[i][j];
    if(A[i] == '*' || B[j] == '*')
    {
        bool ans = solve(A,B,i+1,j,n,m,dp) || solve(A,B,i,j+1,n,m,dp);
        if(ans == false)
            return dp[i][j] = false;
        return dp[i][j] = true;
    }
    if(A[i] == '?' || B[j] == '?' || A[i] == B[j])
        return dp[i][j] = solve(A,B,i+1,j+1,n,m,dp);
    return dp[i][j] = false;
}
int Solution::isMatch(const string A, const string B) {
    int n = A.size();
    int m = B.size();
    vector<vector<bool>> dp(n,vector<bool>(m,true));
    return solve(A,B,0,0,n,m,dp);
}
