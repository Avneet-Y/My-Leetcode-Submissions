class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit1 = 0;
        int minprice1 = INT_MAX;
        int profit2 = 0;
        int minprice2 = INT_MAX;
        
        for(int i=0;i<prices.size();i++)
        {
            minprice1 = min(minprice1 , prices[i]);
            profit1 = max(profit1 , prices[i] - minprice1);
            minprice2 = min(minprice2 , prices[i] - profit1);
            profit2 = max(profit2, prices[i] - minprice2);
        }
        
        return profit2; 
    }
};