class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool> &visited, int curr, long long &count)
    {
        if(visited[curr]) 
            return ;
        visited[curr] = true;
        count++;
        for(auto neighbor: adj[curr])
        {
            dfs(adj, visited, neighbor, count);
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        vector<long long> islands;
        long long res = 0, visct = n;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                long long count=0;
                dfs(adj, visited, i, count);
                res += count * (visct - count);
                visct -= count;
            }
        }
        return res;
    }
};