class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &visited)
    {
        visited[node] = 1;
        for(auto it : adj[node])
        {
            if(visited[it] == 0)
                dfs(it, adj, visited);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isConnected[i][j] == 1 && i != j)
                {
                    adj[j].push_back(i);
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> visited(n, 0);
        
        for(int i=0; i<n; i++)
        {
            if(visited[i] != 1)
            {
                ans++;
                dfs(i, adj, visited);
            }
        }
        return ans; 
    }
};