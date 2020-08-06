#define ll long long
int Solution::solve(vector<vector<int>> &matrix) {
    int n = matrix.size();
    if(n == 0)
        return 0;
    int m = matrix[0].size();
    ll ar[n];
	ll ans = 0ll;
	for(int k=0;k<m;k++)
	{
        memset(ar,0ll,sizeof(ar));
        for(int i=k;i<m;i++)
        {
            for(int j=0;j<n;j++)
	            ar[j] += matrix[j][i];
            unordered_map<int,int> ump;
            ump[0]++;
            ll prefix = 0ll;
            for(int i=0;i<n;i++)
            {
                prefix += ar[i];
                ump[prefix]++;
            }
            for(auto it=ump.begin();it!=ump.end();it++)
            {
                ans += (it->second)*(it->second-1)/2;
            }
	    }
	}
	return ans;
}
