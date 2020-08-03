string Solution::solve(string str) {
    int n = str.size();
    int i = n-1;
    int len = 0;
    string ans = "";
    while(i>=0)
    {
        if(str[i] == ' ')
        {
            ans += str.substr(i+1,len);
            ans += " ";
            i--;
            len = 0;
        }
        else
        {
            i--;
            len++;
        }
    }
    ans += str.substr(0,len);
    return ans;
}
