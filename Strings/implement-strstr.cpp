#define ll long long
int Solution::strStr(const string A, const string B) {
    if(B.size() == 0)
            return 0;
        ll m = B.size();
        ll lps[m];
        ll len = 0ll;
        int i = 1;
        lps[0] = 0ll;
        while(i<m)
        {
            if(B[i] == B[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len != 0)
                    len = lps[len-1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        ll n = A.size();
        int j = 0;
        i = 0;
        while(j<n)
        {
            if(A[j] == B[i])
            {
                i++;
                j++;
            }
            if(i == m)
                return j-i;
            else if(j<n && A[j] != B[i])
            {
                if(i!=0)
                    i = lps[i-1];
                else
                    j++;
            }
        }
        return -1;
}
