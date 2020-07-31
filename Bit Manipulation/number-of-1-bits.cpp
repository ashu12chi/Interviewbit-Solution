int Solution::numSetBits(unsigned int n) {
    int ans = 0;
    for(int i=0;i<32;i++)
    {
        if(n&(1<<i))
            ans++;
    }
    return ans;
}
