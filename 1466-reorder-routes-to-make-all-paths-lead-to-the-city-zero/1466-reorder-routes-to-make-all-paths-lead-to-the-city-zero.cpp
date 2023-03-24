class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, bool>>> mp;
        for(auto it : connections)
        {
            mp[it[0]].push_back({it[1], 1});
            mp[it[1]].push_back({it[0], 0});
        }
        vector<int> visited(n, 0);
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    visited[node] = 1;
                    for(auto it : mp[node])
                    {
                        if(!visited[it.first])
                        {
                            if(it.second == 1)
                            {
                               ans++;
                            }
                            q.push(it.first);
                            visited[it.first] = 1;
                        }
                    }
                }
            }
        }
        return ans;  
    }
};