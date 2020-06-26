vector<int> Solution::flip(string A) {
 //   int c1 = 0;
  //  int c0 = 0;
    int n = A.size();
    int ar[n];
    for(int i=0;i<n;i++)
    {
        if(A[i] == '0')
            ar[i] = 1;
        else
            ar[i] = -1;
    }
    int curr_sum = 0;
    int max_sum = INT_MIN;
    int l,r;
    l = 0;
    r = 0;
    int start = 0;
    for(int i=0;i<n;i++)
    {
        curr_sum += ar[i];
        if(max_sum<curr_sum)
        {
            max_sum = curr_sum;
            r = i;
            start = l;
        }
        if(curr_sum<0)
        {
            curr_sum = 0;
            l = i+1;
        }
    }
    vector<int> ans;
    if(max_sum<0)
        return ans;
    ans.push_back(start+1);
    ans.push_back(r+1);
    return ans;
}
