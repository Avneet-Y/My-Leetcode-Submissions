class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        vector<int> not_lost, one_lost;
        map<int, int> mp;
        for(int i = 0; i < matches.size(); i++) 
        {
            mp[matches[i][0]] += 0;
            mp[matches[i][1]] += 1;
        }
        for(auto it: mp) 
        {
            if(it.second == 0) 
            {
                not_lost.push_back(it.first);
            } 
            else if(it.second == 1) 
            {
                one_lost.push_back(it.first);
            }
        }
        ans.push_back(not_lost);
        ans.push_back(one_lost);
        return ans;
        
    }
};