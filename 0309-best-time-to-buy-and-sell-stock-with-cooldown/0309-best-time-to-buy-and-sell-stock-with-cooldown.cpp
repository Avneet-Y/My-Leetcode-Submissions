class Solution {
public:
    int findMax(vector<int>& prices, int curr, int n, vector<int> &dp)
    {
        if(curr >= n)
            return 0;
        
        if(dp[curr] != -1)
            return dp[curr];

        int maxVal = 0; //find all the positions where we can sell the stock
        for(int i = curr+1; i<n; i++)
            if(prices[curr] < prices[i])  // We can try to sell on ith day
                //We have 2 choices
                //1.We can sell the stock at ith day and findMax from (i+2)th day
                //2.We don't sell the stock on ith day
                maxVal = max(maxVal, (prices[i] - prices[curr]) + findMax(prices, i+2, n, dp));//(i+1)th day is cooldown
        
        maxVal = max(maxVal, findMax(prices, curr+1, n, dp)); // Exclude current element
        dp[curr] = maxVal;
        return maxVal;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> dp(n+1,-1);
        return findMax(prices, 0, n, dp);
    }
};