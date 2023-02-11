class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<pair<int,int>> adj[n];
        
        for(auto edge: redEdges)
        {
            adj[edge[0]].push_back({edge[1], 1});
        }
        
        for(auto edge: blueEdges)
        {
            adj[edge[0]].push_back({edge[1], 0});
        }
        
        queue<pair<int,int>> q;
        q.push({0,-1});  //insert 0 with color -1, as we can go to any color node from this
        vector<int> ans(n, INT_MAX); // shortest distance from 0 to each node
        
        // we can visit each node 2 times max, one time arriving from red edge and going to blue edge, and second time arriving from blue edge going to red edge
        vector<vector<bool>> vis(n, vector<bool>(2, false)); 
        
        vis[0][0] = true;
        vis[0][1] = true;
        int dist = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int node = q.front().first;
                int color = q.front().second;
                q.pop();
                ans[node] = min(ans[node], dist); 
                
                for(auto val: adj[node])
                {
                    // push adjacent node in queue, only if it is not visited from same colored edge and color of this edge is different from previous
                    if(!vis[val.first][val.second] && val.second != color)
                    {
                        q.push(val);
                        vis[val.first][val.second] = true;
                    }
                }
            }
            dist++;
        }
        
        for(auto &val: ans)
        {
            if(val == INT_MAX)
            {
                val = -1;
            }
        }
        return ans;
    }
};