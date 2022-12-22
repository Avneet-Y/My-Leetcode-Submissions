class Solution {
public:
    vector<int> res;
    vector<int> count_node;
    void countdfs(vector<vector<int>>& adj, int u, int parent)
    {
        for(auto v : adj[u])
        {
            if(v == parent)
                continue;
            countdfs(adj, v, u);
            count_node[u] += count_node[v];
            res[u] += res[v] + count_node[v];
        }
        count_node[u]++;
    }
    
    void dfs(vector<vector<int>>& adj, int u, int parent)
    {
        for(auto v : adj[u])
        {
            if(v == parent)
            {
                continue;
            }
            res[v] = res[u] - count_node[v] + (adj.size() - count_node[v]);
            dfs(adj, v, u);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        res.resize(n, 0);
        count_node.resize(n, 0);
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        countdfs(adj, 0, -1);
        dfs(adj, 0, -1); // calculate the distances for every node to the other nodes 
        return res;
    }
};