class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans;
        unordered_map<int, int> mp;
        for(auto it : nums)
            mp[it]++;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(it->second == 1)
                ans = it->first;
        }
        return ans;   
    }
};