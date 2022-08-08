// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         return solve(nums, 0, INT_MIN);
//     }
//     int solve(vector<int>& nums, int i, int prev) 
//     {
//         if(i >= nums.size())
//             return 0;                       // cant pick any more elements
//         int take = 0;
//         int dontTake = solve(nums, i + 1, prev); // try skipping the current element
        
//         if(nums[i] > prev) 
//             take = 1 + solve(nums, i + 1, nums[i]);   // or pick it if it is greater than previous picked element
        
//         return max(take, dontTake);
//     }
// };

// class Solution {
// public:
    
//     int solve(vector<int>& nums, int i, int prev,  vector<vector<int>> &dp) 
//     {
        
//         if(i == nums.size())
//             return 0;                     
        
//         if(dp[i][prev+1] != -1 )
//             return dp[i][prev+1];
        
//         int len = 0 + solve(nums, i + 1, prev, dp); 
        
//         if(prev == -1 || nums[i] > nums[prev]) 
//             len = max(len, 1 + solve(nums, i + 1, i, dp));   
        
//         return  dp[i][prev+1] = len;
//     }
    
//     int lengthOfLIS(vector<int>& nums)
//     {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n+1, -1));
//         return solve(nums, 0, -1, dp);
//     }
// };


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1, n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < i; j++) 
                if(nums[i] > nums[j]) 
				    dp[i] = max(dp[i], dp[j] + 1), ans = max(ans, dp[i]);
        return ans;
            }
};
