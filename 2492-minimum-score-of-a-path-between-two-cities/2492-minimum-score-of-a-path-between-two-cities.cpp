class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj[n+1];
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<int> vis(n+1, 0);
        queue<vector<int>> pq;
        int ans = INT_MAX;
        vis[1] = 1;
        pq.push({1, 100000});
        while(!pq.empty())
        {
            int count = pq.front()[0];
            pq.pop();
            for(auto it : adj[count])
            {
                ans = min(ans, it[1]);
                if(!vis[it[0]])
                {
                    vis[it[0]] = 1;
                    pq.push({it[0], it[1]});
                }
            }
        }
        return ans;
    }
};