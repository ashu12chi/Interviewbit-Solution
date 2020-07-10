int Solution::diffPossible(const vector<int> &ar, int k) {
    unordered_map<int,int> ump;
    for(int i=0;i<ar.size();i++)
    {
        int temp = k + ar[i];
        int temp1 = ar[i] - temp;
        if(ump.find(temp)!=ump.end())
            return 1;
        else if(ump.find(temp1)!=ump.end())
            return 1;
        else
            ump[ar[i]] = 1;
    }
    return 0;
}
