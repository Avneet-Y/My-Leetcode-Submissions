class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_upto_now = INT_MIN;
        int new_max = 0;
        for(int i=0; i<n; i++)
        {
            new_max += nums[i];
            if(new_max > max_upto_now)
            {
                max_upto_now = new_max;
            }
            if(new_max < 0)
                new_max = 0;
        }
        return max_upto_now;
        
    }
};