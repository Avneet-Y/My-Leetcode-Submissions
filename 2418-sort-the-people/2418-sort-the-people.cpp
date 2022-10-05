class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
//         vector<string> ans;
//         unordered_map<int,string> mp;
    
//         for(int i=0; i<names.size(); i++)
//         {
//             mp[heights[i]] = names[i];
//         }
    
//         sort(heights.rbegin(),heights.rend());
    
//         for(int i=0; i<heights.size(); i++)
//         {
//             ans.push_back(mp[heights[i]]);
//         }
    
//         return ans;
        
        priority_queue<pair<int, string>> pq;
        
        for(int i = 0; i < heights.size(); i++)
        {
            pq.push({heights[i], names[i]});
        }
        
        vector<string> ans;
        
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};