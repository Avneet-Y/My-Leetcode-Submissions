class Solution {
public:
    string frequencySort(string s) {
       
//         unordered_map<char,int> mp;
//         string ans;
//         for(int i=0; i<s.size() ; i++)
//         {
//             mp[s[i]]++;
//         }
        
//         priority_queue<pair<int, char>> maxh;
//         for(auto it : mp)
//         {
//             maxh.push({it.second, it.first});
//         }
//         while(maxh.size() !=0 )
//         {
//             int freq = maxh.top().first;
//             int ele = maxh.top().second;
//             for(int i=1; i<=freq; i++)
//             {
//                 ans.push_back(ele);
//             }
//             maxh.pop();
//         }
//         return ans;
       
        unordered_map<char,int>mp;    
        for(auto i :s)
        {
            mp[i]++;
        }
        
        sort(s.begin(), s.end(), [&mp](char a, char b)
             {
                return mp[a] > mp[b] || (mp[a] == mp[b] && a > b); });

       
     return s;
       
     }
};