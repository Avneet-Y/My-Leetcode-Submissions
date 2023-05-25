class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
         if (k == 0 || n >= k + maxPts)
            return 1.0;
        vector<double> dp(n + 1);
        double pt = 1.0, prob = 0.0;
        dp[0] = 1.0;
        for (int i = 1; i <= n; i++) 
        {
            dp[i] = pt / maxPts;
            if (i < k)
                pt += dp[i];
            else
                prob += dp[i];
            if (i - maxPts >= 0)
                pt -= dp[i - maxPts];
        }
        return prob;
    }
};