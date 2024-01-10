class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int newmax = 0, maxuptonow = INT_MIN;
        for(int i=0; i<n; i++)
        {
            newmax += nums[i];
            if(maxuptonow < newmax)
                maxuptonow = newmax;
            if(newmax < 0)
                newmax = 0;
        }
        return maxuptonow;
    }
};