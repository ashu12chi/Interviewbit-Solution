int compare(string& a,string& b)
{
    int n = a.size();
    int m = b.size();
    int i = 0;
    int j = 0;
    while(i<n && a[i] == '0')
        i++;
    while(j<m && b[j] == '0')
        j++;
    if(m-j > n-i)
        return -1;
    else if(m-j < n-i)
        return 1;
    while(i<n && j<m)
    {
        if(a[i] > b[j])
            return 1;
        if(a[i] < b[j])
            return -1;
        i++;
        j++;
    }
    if(i == n && j == m)
        return 0;
    if(i == n)
        return -1;
    return 1;
}
int Solution::compareVersion(string A, string B) {
    int n = A.size();
    int m = B.size();
    int i = 0;
    int start = 0;
    vector<string> v1;
    while(i<n)
    {
        if(A[i] == '.')
        {
            string temp = A.substr(start,i-start);
            int k = 0;
            while(k<temp.size() && temp[k] == '0')
                k++;
            if(k!=temp.size())
                v1.push_back(temp);
            start = i+1;
            i++;
        }
        i++;
    }
   string temp = A.substr(start,n-start);
            int k = 0;
            while(k<temp.size() && temp[k] == '0')
                k++;
            if(k!=temp.size())
                v1.push_back(temp);
    i = 0;
    start = 0;
    vector<string> v2;
    while(i<m)
    {
        if(B[i] == '.')
        {
            string temp = B.substr(start,i-start);
            int k = 0;
            while(k<temp.size() && temp[k] == '0')
                k++;
            if(k!=temp.size())
                v2.push_back(temp);
            start = i+1;
            i++;
        }
        i++;
    }
    temp = B.substr(start,n-start);
            k = 0;
            while(k<temp.size() && temp[k] == '0')
                k++;
            if(k!=temp.size())
                v2.push_back(temp);
    i = 0;
    while(i<v1.size() && i<v2.size())
    {
        int res = compare(v1[i],v2[i]);
        if(res != 0)
            return res;
        i++;
    }
    if(v1.size() == v2.size())
        return 0;
    else if(v1.size() > v2.size())
        return 1;
    return -1;
}
