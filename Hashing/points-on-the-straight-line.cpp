int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    if(n <= 1)
        return n;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        map<pair<double,double>,int> ump;
        double x1 = A[i];
        double y1 = B[i];
        for(int j=0;j<n;j++)
        {
            if(j == i)
                continue;
            double x2 = A[j];
            double y2 = B[j];
            double m,c;
            if(x2 == x1)
            {
                m = INT_MAX;
                c = x1;
            }
            else
            {
                m = (y2-y1)/(x2-x1);
                c = y1-m*x1;
            }
            ump[{m,c}]++;
            ans = max(ans,ump[{m,c}]);
        }
    }
    return ans+1;
}
