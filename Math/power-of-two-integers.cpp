int Solution::isPower(int A) {
    if(A==1) 
        return 1;
    int x=A;
    for(int i=2;i<=sqrt(A);i++)
    {
        while(x!=0 && x%i==0)
        {
            x /= i;
        }
        if(x==1)
        {
            return 1;
        }
        else
        {
            x=A;
        }
    }
    return 0;
}
