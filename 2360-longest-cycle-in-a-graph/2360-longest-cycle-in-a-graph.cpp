class Solution {
public:
    void dfs(vector<int>& edges, int u, vector<bool>& visited, int &count)
    {
        visited[u] = true;
        count++;
        if(edges[u] != -1 && visited[edges[u]] == false)
        {
            dfs(edges, edges[u], visited, count);
        }
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++)
        {
            int v = edges[i];    
            if(v != -1)
            {
                indegree[v]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int u = q.front(); 
            q.pop(); 
            if(edges[u] != -1)
            {
                indegree[edges[u]]--;    
                if(indegree[edges[u]] == 0)
                {
                    q.push(edges[u]);
                }
            }
        }
        vector<bool> visited(n, false);
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            int count = 0;   
            if(indegree[i] > 0 && visited[i] == false)
            {
                dfs(edges, i, visited, count);
            }   
            maxi = max(maxi, count);
        }
        if(maxi == 0)
            return -1;
        return maxi;
    }
};