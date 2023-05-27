class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto i : nums)
            mp[i]++;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(it->second > 1)
                return it->first;
        }
        return 0;
    }
};