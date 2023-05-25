class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int sell = 0;
        for(int i=0; i<n; i++)
        {
            if(prices[i] < buy)
            {
                buy = prices[i];
            }
            sell  = max(sell, prices[i] - buy);
        }
        return sell;
    }
};