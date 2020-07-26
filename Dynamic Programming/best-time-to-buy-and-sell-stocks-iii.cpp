int Solution::maxProfit(const vector<int> &prices) {
    if(prices.size()<=1) 
        return 0;
    int buy1=INT_MIN,buy2=INT_MIN,sell1=0,sell2=0;
     for(int i=0;i<prices.size();i++)
     {
         buy1=max(buy1,-prices[i]);
         sell1=max(sell1,buy1+prices[i]);
         buy2=max(buy2,sell1-prices[i]);
         sell2=max(sell2,buy2+prices[i]);
     }
    return sell2;
}
