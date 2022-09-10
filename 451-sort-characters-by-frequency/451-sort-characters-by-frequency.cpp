class Solution {
public:
    string frequencySort(string s) {
       
        unordered_map<char,int> mp;
        string ans;
        for(int i=0; i<s.size() ; i++)
        {
            mp[s[i]]++;
        }
        
        priority_queue<pair<int, char>> maxh;
        for(auto it : mp)
        {
            maxh.push({it.second, it.first});
        }
        while(maxh.size() !=0 )
        {
            int freq = maxh.top().first;
            int ele = maxh.top().second;
            for(int i=1; i<=freq; i++)
            {
                ans.push_back(ele);
            }
            maxh.pop();
        }
        return ans;
     }
};