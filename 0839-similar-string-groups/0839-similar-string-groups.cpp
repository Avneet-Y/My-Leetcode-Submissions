class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<bool>&vis, int curr)
    {
        vis[curr] = true;
        for(int adjNode : adj[curr])
        {
            if (vis[adjNode]) 
                continue;
            dfs(adj, vis, adjNode);
        }
    }
    int help(vector<vector<int>> &adj)
    {
        int n = adj.size(), ct = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            if (vis[i]) 
                continue;
            dfs(adj, vis, i);
            ct++;
        }
        return ct;
    }
    bool issame(string& s1, string& s2)
    {
        int diff = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i]) 
                diff++;
        }
        return (diff == 0 || diff == 2);
    }
    int numSimilarGroups(vector<string>& strs) 
    {
        int n = strs.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (issame(strs[i], strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans = help(adj);
        return ans;
    }
};