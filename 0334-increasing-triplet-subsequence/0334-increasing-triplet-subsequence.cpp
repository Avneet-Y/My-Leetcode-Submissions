class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_left(n);
        vector<int> maxright(n);
        min_left[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            min_left[i] = min(min_left[i - 1], nums[i]);
        }
        maxright[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            maxright[i] = max(maxright[i + 1], nums[i]);
        }
        for(int i = 1; i < n - 1; i++)
        {
            if(min_left[i - 1] < nums[i] && nums[i] < maxright[i + 1])
            {
                return true;
            }
        }
        return false;
        
    }
};