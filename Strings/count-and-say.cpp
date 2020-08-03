string Solution::countAndSay(int n) {
    string ans = "1";
    for(int i=1;i<n;i++)
    {
        char prev = ans[0];
        int count = 1;
        string temp = "";
        for(int j=1;j<ans.size();j++)
        {
            if(ans[j] == prev)
                count++;
            else
            {
                temp += to_string(count);
                temp += prev;
                prev = ans[j];
            }
        }
        temp += (char)(count+'0');
        temp += prev;
        ans = temp;
    }
    return ans;
}
