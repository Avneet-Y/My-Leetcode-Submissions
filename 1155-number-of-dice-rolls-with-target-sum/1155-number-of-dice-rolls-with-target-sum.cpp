class Solution {
public:
     #define mod 1000000007
    int numRollsToTarget(int n, int faces, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));    
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= target; j++)
            {
                for(int k = 1; k <= faces; k++)
                {
                    if(j>=k)
                    {
                        dp[i][j] = (dp[i][j] + dp[i-1][j - k]) % mod; 
                    }
                    else
                    {
                        dp[i][j] = (dp[i][j]) % mod;
                    }
                }
            }
        }
                
    return dp[n][target];
    }
};