class Solution {
public:
    int dp[301][11];
    int solve(vector<int> &jobDifficulty, int n, int index, int d)
    {
         if(d == 1)
        {
            int maxd = jobDifficulty[index];
            for(int i=index; i<n; i++)
            {
                maxd = max(maxd, jobDifficulty[i]);
            }
            return maxd;     
        }
    if(dp[index][d] != -1)
        return dp[index][d];
        
    int maxd = jobDifficulty[index];
    int ans = INT_MAX;
    for(int i = index; i <= n-d; i++)
        { 
            maxd = max(maxd, jobDifficulty[i]);
            int result = maxd + solve(jobDifficulty, n, i+1, d-1);
            ans = min(ans, result);
        }
        return dp[index][d] = ans;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        if(n < d)
            return -1;
        memset(dp, -1, sizeof(dp));
        return solve(jobDifficulty, n, 0, d);
        
    }
};