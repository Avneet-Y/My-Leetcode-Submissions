class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
//         int buy = prices[0];
//         int sell = 0;
//         for(int i=1; i<prices.size(); i++)
//         {
//             if(prices[i]<buy)
//                 buy = prices[i];
//              else if (prices[i] - buy > sell)
//                  sell = prices[i] - buy;
//         }
       
//         return sell;
        int n = prices.size();
        if(n<=1 || k<=0)
            return 0;
        int profit = 0;
        if(k >= n/2)
        {
            for(int i=0; i<n-1 ;i++)
            {
                if(prices[i]<prices[i+1])
                    profit += prices[i+1] - prices[i];
            }
            return profit;
        }
       // int mn = INT_MIN;
        vector<int> buy(k, INT_MIN);
        
        vector<int> sell(k);
        // for(int i=0; i<k; i++)
        //     sell.push_back(0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<k; j++)
            {
                buy[j] = max(buy[j], j==0 ? 0-prices[i] : sell[j-1]-prices[i]);
                sell[j] = max(sell[j], buy[j]+prices[i]);
            }
        }
        return sell[k-1];
        
    }
};