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