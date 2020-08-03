bool isPalindromic(string &str,int n)
{
    int i = 0;
    int j = n-1;
    while(i<j)
    {
        if(str[i] == str[j])
        {
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}
int Solution::solve(string str) {
    int n = str.size();
    for(int i=0;i<n;i++)
    {
        if(isPalindromic(str,n-i))
            return i;
    }
}
