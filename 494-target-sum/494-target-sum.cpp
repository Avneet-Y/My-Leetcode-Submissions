class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        
//         for(int i=0; i<n; i++)
//         {
//             sum += nums[i];
//         }
        
//         if (target > sum || target < (-sum)) 
//             return 0;
        
//         int s1 = (sum + target) / 2;
//         int s2 = s1 - target;
//         if (s1 + s2 < sum) 
//             return 0;

//         int dp[n + 1][s1 + 1];
//         dp[0][0] = 1;
        
//         for (int j = 1; j < s1 + 1; j++) 
//         {
//             dp[0][j] = 0;
//         }
        
//         for(int i=1; i<n+1; i++)
//         {
//             for(int j=0; j<s1+1; j++)
//             {
//                 if(nums[i-1] <= j)
//                     dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
//                 else
//                     dp[i][j] = dp[i-1][j];
//             }
//         }
//         return dp[n][s1];
         
           for(int i=0; i<n; i++)
           {
               sum += nums[i];
           }
           if(sum < abs(target) || (target + sum) %2 != 0) 
               return 0;
    
           int build = (sum - target)/2;
           int dp[n + 1][build + 1];
           //dp[0][0] = 1;
           for(int i=0; i<build+1; i++)
           {
               dp[0][i] = 0;
           }
           for(int j=0; j<n+1; j++)
           {
               dp[j][0] = 1;
           }
        for(int i=1; i < n+1; i++) 
            {
                for(int j=0; j < build+1; j++) 
                {
                    if(nums[i - 1] <= j)
                        dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i - 1]];
                    else
                        dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][build];
        
    }
};