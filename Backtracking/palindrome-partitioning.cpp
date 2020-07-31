vector<vector<string>> ans;
int n;
bool isPalindrome(string& str,int i,int j)
{
    while(i<j)
    {
        //cout << i << " " << j << "* ";
        if(str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}
void solve(string& str,int index,vector<string>& ashu)
{
    if(index == n)
    {
        ans.emplace_back(ashu);
        return;
    }
    int len = n-index;
    for(int i=1;i<=len;i++)
    {
        if(isPalindrome(str,index,index+i-1))
        {
            ashu.push_back(str.substr(index,i));
            solve(str,index+i,ashu);
            ashu.pop_back();
        }
    }
}
vector<vector<string> > Solution::partition(string str) {
    ans.clear();
    n = str.size();
    vector<string> ashu;
    solve(str,0,ashu);
    //isPalindrome(str,0,2);
    return ans;
}
