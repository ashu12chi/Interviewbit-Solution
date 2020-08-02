int Solution::singleNumber(const vector<int> &ar) {
    vector<int> bits(32,0);
    for(int i=0;i<ar.size();i++)
    {
        for(int j=0;j<32;j++)
        {
            if(ar[i]&(1<<j))
                bits[j]++;
        }
    }
    int ans = 0;
    for(int i=0;i<32;i++)
    {
        if(bits[i]%3==1)
            ans += pow(2,i);
    }
    return ans;
}
