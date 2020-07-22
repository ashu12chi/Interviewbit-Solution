unordered_map<string,int> mp;
int Solution::isScramble(const string A, const string B) {
    if(A == B)
        return 1;
    if(A.size()<=1)
        return 0;
    string key=A;
    key += " ";
    key += B;
    if(mp.find(key) != mp.end())
        return mp[key];
    int n = A.size();
    int ans = 0;
    for(int i=1;i<n;i++)
    {
        if(((isScramble(A.substr(0,i),B.substr(n-i,i))==1) && (isScramble(A.substr(i,n-i),B.substr(0,n-i))==1))||((isScramble(A.substr(0,i),B.substr(0,i))==1) && (isScramble(A.substr(i),B.substr(i))==1)))
        {
            ans = 1;
            break;
        }
    }
    mp[key] = ans;
    return ans;
}
