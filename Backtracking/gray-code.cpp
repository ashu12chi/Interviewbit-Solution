vector<int> ans;
void solve(int n,int& num)
{
    if(n == 0)
    {
        ans.push_back(num);
        return;
    }
    solve(n-1,num);
    num ^= (1<<(n-1));
    solve(n-1,num);
}
vector<int> Solution::grayCode(int n) {
   ans.clear();
   int num = 0;
   solve(n,num);
   return ans;
}
