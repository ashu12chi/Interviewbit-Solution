int Solution::removeDuplicates(vector<int> &ar) {
    int n = ar.size();
    int i = 0;
    int j = 0;
    while(i<n)
    {
        ar[j++] = ar[i];
        i++;
        while(i<n && ar[i] == ar[i-1])
            i++;
    }
    ar.resize(j);
    return j;
}
