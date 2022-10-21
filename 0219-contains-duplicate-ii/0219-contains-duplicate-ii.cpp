class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) 
        {
            if(mp.find(nums[i])!=mp.end()) 
            {  
                if(abs(i - mp[nums[i]]) <= k)   //mp[nums[i]] have last poa of that ele
                    return true;               //get diff of that and curr pos we are on
            }   
            mp[nums[i]] = i;
        }
        return false;
    }
};