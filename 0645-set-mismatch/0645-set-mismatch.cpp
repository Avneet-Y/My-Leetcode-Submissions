class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        map<int, int> mp;
        for(auto i : nums)
            mp[i]++;
        for(auto it = mp.begin(); it!= mp.end(); it++)
        {
            if(it->second > 1)
                ans.push_back(it->first);
        }
        for(int i = 1; i <= nums.size(); i++)
        {
            if(mp.find(i) == mp.end())
            {
                ans.push_back(i);
            }
        }
        return ans;            
    }
};