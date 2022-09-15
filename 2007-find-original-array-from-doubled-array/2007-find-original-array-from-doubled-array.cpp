class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        unordered_map<int, int> mp;
        
        for(auto i : changed)
        {
            mp[i]++;
        }
        
        sort(changed.begin(), changed.end());
        
        for(auto i : changed)
        {
            if(mp.find(i * 2) != mp.end() && mp[i] && mp[i * 2])
            {
                mp[i]--;
                mp[i * 2]--;
                ans.push_back(i);
            }
        }
    
        for(auto it : mp)
        {
            if(it.second != 0)
            {
                return {};
            }
        }
        return ans;
    }
};

static const auto speedup = []() {
std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
}();