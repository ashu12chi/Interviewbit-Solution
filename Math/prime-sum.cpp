bool prime[16777215];
vector<int> Solution::primesum(int n) {
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++) 
    {
        if (prime[p] == true) 
        {
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    }
    vector<int> ans;
    for(int i=2;i<=n;i++)
    {
        if(prime[i] && prime[n-i])
        {
            ans.push_back(i);
            ans.push_back(n-i);
            return ans;
        }
    }
    ans.push_back(0);
    ans.push_back(0);
    return ans;
}
