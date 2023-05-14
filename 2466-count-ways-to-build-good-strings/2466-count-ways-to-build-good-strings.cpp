class Solution {
public:
     long long  help(int len, int high, vector<long long>& dp, int low, int zero,int one)      {
        long long mod = 1e9 + 7;
         if(len > high) 
            return 0;
        if(dp[len] != -1) 
            return dp[len];
        dp[len] = len >= low ? 1 : 0;
         
        dp[len] += help(len + zero, high, dp, low, zero, one) + help(len + one, high, dp, low, zero, one);
        
         return dp[len] % mod; 
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high + 1,-1);
        return help(0, high, dp, low, zero, one);
        
    }
};