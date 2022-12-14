class Solution {
public:
    
    int solve(vector<int> &nums, int target, int n)
    {
        bool dp[n+1][target+1];
        for(int i=0; i < n+1; i++)
        {
            for(int j=0; j < target+1; j++)
            {
                if(i == 0)
                    dp[i][j] = false;
                if(j == 0)
                    dp[i][j] = true;
            }
        }
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<target+1; j++)
            {
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n ; i++)
        {
            sum += nums[i];
        }
        if(sum%2 != 0)
            return false;
        int targetsum = sum/2;
        return solve(nums, targetsum, n);
        
    }
};