class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0, curr_sum1 = 0, curr_sum2 = 0;
        int max_sub = INT_MIN, minsum_sub = INT_MAX;   
        for(int i=0; i<n; i++)
        {
            total_sum += nums[i]; 
            curr_sum1 += nums[i]; 
            curr_sum2 += nums[i];
            max_sub = max(max_sub, curr_sum1);
            if(curr_sum1 < 0)
            {
                curr_sum1=0;
            }
            
            minsum_sub = min(curr_sum2,minsum_sub);
            
            if(curr_sum2 > 0)
            {
                curr_sum2 = 0;
            }
        }
        if(total_sum == minsum_sub)
            return max_sub;
        return max(max_sub, total_sum - minsum_sub);
        
    }
};