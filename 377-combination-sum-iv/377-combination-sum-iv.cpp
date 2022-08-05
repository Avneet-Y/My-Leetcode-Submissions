class Solution {
public:
   int Solvemem(vector<int> nums, int target, vector<int> &dp)
    {
        if(target < 0)
            return 0;
       
       if(target == 0)
           return 1;
       
       if(dp[target] != -1)
           return dp[target];
       
       int ans = 0 ;
       for(int i=0; i<nums.size();i++)
       {
           ans += Solvemem(nums, target - nums[i], dp);
       }
       
       dp[target] = ans;
       
       return dp[target]; 
    }
    
    int combinationSum4(vector<int>& nums, int target) { 
        
       vector<int> dp(target+1 ,-1);
       return Solvemem(nums,target,dp);           
    }
};

