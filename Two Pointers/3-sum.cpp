int Solution::threeSumClosest(vector<int> &ar, int b) {
    int n = ar.size();
    sort(ar.begin(),ar.end());
    long long diff = INT_MAX;
    long long ans = b;
    for(int i=0;i<n-2;i++)
    {
        int left = i+1;
        int right = n-1;
        while(left < right)
        {
            long long sum = ar[i]+ar[left]+ar[right];
            if(abs(b-sum) < diff)
            {
                diff = abs(b-sum);
                ans = sum;
            }
            if(sum < b)
                left++;
            else
                right--;
        }
    }
    return ans;
}
