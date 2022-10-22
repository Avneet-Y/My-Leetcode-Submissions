/*

class Solution {
public:

    int climbStairs(int n) {
       if (n <= 2)
           return n;
        int prev = 2, prev1 = 1, ans;
        for (int i = 3; i <= n; i++) 
        {
            ans = prev + prev1;
            prev1 = prev;  
            prev = ans;
        }
        return ans;
        
    }
};


*/
class Solution {
public:
    int memosol(int n, vector<int> &dp)
    {
        if(n < 0)
            return 0;
        if(n == 0)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = memosol(n-1, dp) + memosol(n-2, dp);
        
    }
    int climbStairs(int n) {
       vector<int> dp(n+1, -1);
       return memosol(n, dp);  
    }
};