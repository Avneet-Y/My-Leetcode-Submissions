class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        int pre_sum = 0;
        
        for(int i=0 ;i<n; i++)
        {
            pre_sum += nums[i];
            int rem = pre_sum % k;
            if(rem == 0 && i > 0)
                return true;
            
            if(mp.find(rem) == mp.end())
            {
                mp[rem] = i;
            }
            else if(i - mp[rem] >= 2)
            {
                return true;
            }
        }
        return false;
    }
};