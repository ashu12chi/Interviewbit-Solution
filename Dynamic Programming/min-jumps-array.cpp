int Solution::jump(vector<int> &ar) {
    int n = ar.size();
    int maxi = ar[0];
    int jumps = 1;
    int poss = -1;
    if(n == 1)
        return 0;
    for(int i=1;i<n;i++)
    {
        if(i>maxi)
        {
            jumps++;
            maxi = poss;
            poss = -1;
        }
        if(i<= maxi && i + ar[i] > poss)
        {
           poss = i + ar[i];
        }
    }
    if(maxi < n-1 || poss == -1)
        jumps = -1;
    return jumps;
}
