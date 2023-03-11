class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        string ans = "";
        priority_queue<pair<int, char>> maxh;
        for(auto it : s)
            mp[it]++;
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            maxh.push({it->second, it->first});
        }
        while(!maxh.empty())
        {
            int freq = maxh.top().first;
            char ele = maxh.top().second;
            for(int i=0; i<freq; i++)
            {
                ans.push_back(ele);
            }
            maxh.pop();
        }
        //reverse(ans.begin(), ans.end());
        return ans; 
    }
};