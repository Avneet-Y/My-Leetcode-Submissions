// class Solution {
// public:
//     int dp[401];
//     int solve(vector<int> &nums, int i)
//     {
//         if(dp[i] != -1)
//             return dp[i];
//         if(i >= nums.size())
//             return 0;
//         return dp[i] = max(nums[i] + solve(nums, i + 2), solve(nums, i + 1));
//     }
//     int rob(vector<int>& nums) {
//         memset(dp, -1, sizeof(dp));
//         return solve(nums, 0);
//     }
// };


class Solution {
public:
   
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        if(n == 1)
            return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; i++)
        {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};