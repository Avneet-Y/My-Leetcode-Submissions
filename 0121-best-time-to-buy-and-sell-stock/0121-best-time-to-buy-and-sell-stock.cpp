class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0], max = 0;
         for (int i = 1; i < n; i++) {
             if (buy > prices[i])
                 buy = prices[i];
             else if (prices[i] - buy > max)
                 max = prices[i] - buy;
         }
        return max;
    }
};