class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int temp1 = nums[n-1] - nums[2];
        int temp2 = nums[n-2] - nums[1];
        int temp3 = nums[n-3] - nums[0];
        int ans = min(min(temp1, temp2), temp3);
        
        return ans;
        
    }
};