int Solution::colorful(int A) {
    vector<int> num;
    while(A)
    {
        num.push_back(A%10);
        A /= 10;
    }
    reverse(num.begin(),num.end());
    unordered_map<int,int> ump;
    for(int i=0;i<num.size();i++)
    {
        int product = 1;
        for(int j=i;j<num.size();j++)
        {
            product *= num[j];
            if(ump.find(product) != ump.end())
            {
                return 0;
            }
            else
                ump[product] = 1;
        }
    }
    return 1;
}
