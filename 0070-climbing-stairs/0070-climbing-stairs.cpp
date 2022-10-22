/* Using array

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

//Memoziation
/*

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

*/

class Solution {
public:
    
    int climbStairs(int n) {
        
        int dp[46];
        if(n < 1)
            return 0;
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2; i<n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];  
    }
};
