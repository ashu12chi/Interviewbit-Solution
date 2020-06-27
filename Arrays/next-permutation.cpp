vector<int> Solution::nextPermutation(vector<int> &nums) {
    int i = nums.size()-1;
    while(i>0)
        {
            if(nums[i-1] < nums[i])
                break;
            i--;
        }
        if(i == 0)
            reverse(nums.begin(),nums.end());
        else
        {
            int val = nums[i-1];
            int j = nums.size()-1;
            while(j >= i)
            {
                if(nums[j]>val)
                    break;
                j--;
            }
            swap(nums[j],nums[i-1]);
            reverse(nums.begin()+i,nums.end());
        }
    return nums;
}
