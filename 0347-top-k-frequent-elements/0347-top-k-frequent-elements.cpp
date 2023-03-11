class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        priority_queue< pair<int, int>, vector<pair <int, int>>, greater<pair <int, int>>>  minh;
        map<int , int> mp;
        for(auto it : nums)
            mp[it]++;
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            minh.push({it->second, it->first});
            if(minh.size() > k)
                minh.pop();
        }
        while(!minh.empty())
        {
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};