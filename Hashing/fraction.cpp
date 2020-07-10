#define ll long long
string Solution::fractionToDecimal(int a,int b) {
    ll A = a;
    ll B = b;
    if(A == 0)
        return "0";
    string ans = "";
    if(A<0 ^ B<0)
        ans += "-";
    A = abs(A);
    B = abs(B);
    ll num1 = A/B;
    ans += to_string(num1);
    unordered_map<ll,ll> ump;
    ll rem = A%B;
    if(rem == 0)
        return ans;
    ans += '.';
    string res = "";
    while(true)
    {
        if(rem == 0)
        {
            ans += res;
            return ans;
        }
        if(ump.find(rem) != ump.end())
        {
            ll i = ump[rem];
            res.insert(i,"(");
            ans += res;
            ans += ')';
            return ans;
        }
        ump[rem] = res.length();
        rem *= 10;
        ll temp = rem/B;
        res += to_string(temp);
        rem = rem%B;
    }
}
