int Solution::maxArr(vector<int> &ar) {
    int n = ar.size();
    vector<int> v;
    for(int i=0;i<n;i++)
        v.push_back(ar[i]+i);
    sort(v.begin(),v.end());
    int ans = v[n-1] - v[0];
    v.clear();
    for(int i=0;i<n;i++)
        v.push_back(ar[i]-i);
    sort(v.begin(),v.end());
    ans = max(ans,v[n-1]-v[0]);
    return ans;
}
