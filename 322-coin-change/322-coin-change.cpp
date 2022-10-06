/*

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<amount+1; j++)
            {
                if(i == 0)
                    dp[i][j] = INT_MAX - 1;
                if(j == 0)
                    dp[i][j] = 0;
            }
        }
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<amount+1; j++)
            {
                if(i == 1)
                {
                    if(j % coins[0] == 0)
				        dp[i][j] = j/coins[0];
				    else
				        dp[i][j] = INT_MAX-1;
                }
                if(coins[i-1] <= j)
                    dp[i][j] = min(1 + dp[i][j - coins[i-1]] , dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        if(dp[n][amount] == INT_MAX - 1)
        {  
            return -1; 
        }
        else
        {
            return dp[n][amount]; 
        }
        return dp[n][amount];
        
    }
};


*/


class Solution {
  public:
    int coinChange(vector < int > & coins, int amount) {

      int n = coins.size();
      long long t[n + 1][amount + 1];
      for (int i = 0; i <= n; i++)
        t[i][0] = 0;

      for (int j = 1; j <= amount; j++)
        t[0][j] = INT_MAX;

      for (int i = 1; i <= n; i++) 
      {
        for (int j = 1; j <= amount; j++) 
        {
          if (coins[i - 1] <= j)
            t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
          else
            t[i][j] = t[i - 1][j];
        }
      }
      if (t[n][amount] == INT_MAX) 
          return -1;
      return t[n][amount];
    }
};