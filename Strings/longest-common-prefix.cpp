string Solution::longestCommonPrefix(vector<string> &A) {
    int j = 0;
    while(true)
    {
        if(j == A[0].size())
            break;
        bool flag = true;
        for(int i=1;i<A.size();i++)
        {
            if(j == A[i].size() || A[i][j]!=A[0][j])
            {
                flag = false;
                break;
            }
        }
        if(flag)
            j++;
        else
            break;
    }
    return A[0].substr(0,j);
}
