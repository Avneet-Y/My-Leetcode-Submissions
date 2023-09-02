class Solution {
public:
    
    int subset(vector<int>& nums, int n, int subsetfind)
    {
        int dp[n+1][subsetfind+1];
        
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<subsetfind+1; j++)
            {
                if(i == 0)
                    dp[i][j] = 0;
                if(j == 0)
                    dp[i][j] = 1;
            }
        } 
        
        for(int i=1; i<n+1; i++)
        {
            for(int j=0; j<subsetfind+1; j++)
            {
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][subsetfind];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = 0;
        int subsetfind = 0;
        
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
        }
        if(sum < abs(target) || (target + sum) %2 != 0) 
               return 0;
        
        subsetfind = (sum+target)/2;
        int ans = subset(nums, n, subsetfind);
        return ans;
    }
};