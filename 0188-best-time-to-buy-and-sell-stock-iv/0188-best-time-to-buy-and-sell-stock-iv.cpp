/*
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

*/


class Solution {
public:
    // if state == true => we have to buy the stock
    // if state == false => we have to sell the stock
    // initially state will be true, b/c first we have to buy the stock 
    // declare a dp
    
    int dp[1005][105][2];
    
    int dfs(vector<int>& prices, int i, int n, int k, bool state)
    { 
        if(k < 0)   // if there is no. transactions remaining  
            return 0;
        
        if(i == n)  //if there is no. element remaining
        {
            return 0;
        }
        
        
        if(dp[i][k][state] != -1)
            return dp[i][k][state];
        
        int maxi = INT_MIN;
        
        // we have two option either include the curr_element or exclude
        // inclusion part (either we buying or selling depends on state)
        
        if(state)
        {
            maxi = max(maxi, - prices[i] + dfs(prices, i + 1, n, k - 1, !state));
        }
        else
        {
            maxi = max(maxi, prices[i] + dfs(prices, i + 1, n, k, !state));
        }
        
        // exclusion part
        maxi = max(maxi, dfs(prices, i + 1, n, k, state));
        return dp[i][k][state] = maxi;  // store the res then return 
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return dfs(prices, 0, n, k, true);
    }
};