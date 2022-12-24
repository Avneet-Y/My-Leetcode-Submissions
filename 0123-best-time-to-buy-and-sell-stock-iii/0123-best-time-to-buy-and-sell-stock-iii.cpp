/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit1 = 0;
        int minprice1 = INT_MAX;
        int profit2 = 0;
        int minprice2 = INT_MAX;
        
        for(int i=0; i<prices.size(); i++)
        {
            minprice1 = min(minprice1 , prices[i]);
            profit1 = max(profit1 , prices[i] - minprice1);
            minprice2 = min(minprice2 , prices[i] - profit1);
            profit2 = max(profit2, prices[i] - minprice2);
        }
        
        return profit2; 
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> left(n), right(n);
        
        int lmin = prices[0];
        int rmax = prices[n-1];
        if(n == 0)
            return 0;
        
        for(int i=1; i<n; i++)
        {
            left[i] = max(left[i-1], prices[i] - lmin);
            lmin = min(lmin, prices[i]);
        }
        for(int i=n-2; i>=0; i--)
        {
            right[i] = max(right[i+1], rmax - prices[i]);
            rmax = max(rmax, prices[i]);
        }
        int profit = right[0];
        
        for(int i=1; i<n; i++)
        {
            profit = max(profit, left[i-1] + right[i]);
        }
        return profit;
    }
};