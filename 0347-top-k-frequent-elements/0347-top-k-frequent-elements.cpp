class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto it : nums)
            mp[it]++;
        priority_queue<pair<int,int>,vector<pair<int, int>>, greater<pair<int, int>>> minh;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            minh.push({it->second, it->first});
            while(minh.size() > k)
            {
                minh.pop();
            }
        }
        while(minh.size() != 0)
        {
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};