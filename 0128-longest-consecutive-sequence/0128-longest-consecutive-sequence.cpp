class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        for(int i=0; i<n; i++)
        {
            if(mp.find(nums[i]-1) == mp.end())
            {
                int curr = 1;
                while(mp.find(nums[i]+curr) != mp.end())
                    curr++;
                count = max(count, curr);
            }
        }
        return count;
        
        
    }
};