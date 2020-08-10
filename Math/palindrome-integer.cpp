int Solution::isPalindrome(int n) {
    string str = to_string(n);
    int i = 0;
    int j = str.size()-1;
    while(i<j)
    {
        if(str[i]!=str[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
