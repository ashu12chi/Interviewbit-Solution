bool valid(char c)
{
    if(c >= 'a' && c<= 'z')
        return true;
    if(c >= 'A' && c<= 'Z')
        return true;
    if(c >= '0' && c<= '9')
        return true;
    return false;
}
int Solution::isPalindrome(string str) {
    int i = 0;
    int j = str.size()-1;
    while(i<j)
    {
        if(!valid(str[i]))
        {
            i++;
            continue;
        }
        if(!valid(str[j]))
        {
            j--;
            continue;
        }
        if(str[i] == str[j])
            ;
        else
        {
            char c1 = str[i],c2 = str[j];
            if(str[i]>='A' && str[i]<='Z')
            {
                c1 = str[i] + 32;
            }
            if(str[j]>='A' && str[j]<='Z')
            {
                c2 = str[j] + 32;
            }
            if(c1 != c2)
                return false;
        }
        i++;
        j--;
    }
    return true;
}
