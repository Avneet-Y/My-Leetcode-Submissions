class Solution {
public:
    bool dfs(int node, vector<int> &visited, vector<int> &samepath, vector<vector<int>>& graph, vector<int> &check)
    {
        visited[node] = 1;
        samepath[node] = 1;
        check[node] = 0;
        for(auto it : graph[node])
        {
            if(visited[it] == 0)
            {
                if(dfs(it, visited, samepath, graph, check) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if(samepath[it] == 1)
            {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        samepath[node] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        vector<int> samepath(n, 0);
        vector<int> check(n, 0);
        
        vector<int> safenode;
        
        for(int i=0; i<n; i++)
        {
            dfs(i, visited, samepath, graph, check);
        }
        for(int i=0; i<n; i++)
        {
            if(check[i] == 1)
                safenode.push_back(i);
        }
        
        return safenode;
        
    }
};