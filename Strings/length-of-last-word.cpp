int Solution::lengthOfLastWord(const string str) {
    int n = str.size();
    int i = n-1;
    while(i>=0 && str[i]==' ')
        i--;
    int count = 0;
    while(i>=0 && str[i]==' ')
    {
        count++;
        i--;
    }
    return count;
}
