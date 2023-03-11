class Solution {
public:
    class comparator{
        public:
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> minh;
        
        for(auto it : nums)
            mp[it]++;
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            minh.push({it->second, it->first});           
        }
        while(!minh.empty())
        {
            int freq = minh.top().first;
            int ele = minh.top().second;
            for(int i=1; i<=freq; i++)
            {
                ans.push_back(ele);
            }
            minh.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};