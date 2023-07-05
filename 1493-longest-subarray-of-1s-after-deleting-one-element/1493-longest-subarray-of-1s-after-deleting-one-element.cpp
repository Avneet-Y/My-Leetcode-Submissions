class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        int ct = 0;
        int left = 0;
        int right = 0;
        while(right <  n)
        {
            if(nums[right] == 0) 
                ct++;
            if(ct <= 1)
            {
                ans = max(ans, right-left);
                right++;
            }
            else
            {
                while(ct>1)
                {
                    if(nums[left] == 0) 
                        ct--;
                    left++;
                }
                ans = max(ans, left-right);
                right++;
            } 
        }
        return ans;
    }
};