int Solution::singleNumber(const vector<int> &ar) {
    int ans = 0;
    for(int i=0;i<ar.size();i++)
        ans = ans^ar[i];
    return ans;
}
