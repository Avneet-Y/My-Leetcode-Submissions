class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 0;
        for(int i=1; i<n; i++)
        {
            if(prices[i] > prices[i-1])
                buy += prices[i] - prices[i-1];
        }
        return buy;
    }
};



























// ;
//         for(int i = 1; i < n; i++) 
//         {
//             if (prices[i] > prices[i - 1])
//                 buy += prices[i] - prices[i - 1];
//         }
//         return buy;