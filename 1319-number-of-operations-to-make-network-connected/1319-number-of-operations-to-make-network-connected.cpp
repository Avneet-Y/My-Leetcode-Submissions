class Solution {
public:
        void dfs(vector<int> adj[], int i, vector<int> &vis)
        {
        for(auto it : adj[i])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                dfs(adj, it ,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1 > connections.size())
            return -1;
        vector<int> adj[n];
        vector<int> vis(n,0);
        int cnt = 0;
        for(auto i : connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i = 0; i<n; i++)
        {
              if(!vis[i])
              {
                  vis[i] = 1;
                  cnt++;
                  dfs(adj, i, vis);
              }
        }
        return cnt-1;
    }
};