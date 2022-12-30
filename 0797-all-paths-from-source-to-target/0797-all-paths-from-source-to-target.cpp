class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int s,int d, vector<vector<int>> graph, vector<int>&v)
    {
        if(s == d)
        {
            ans.push_back(v);
            return;
        }
        
        for(auto i : graph[s])
        {
            v.push_back(i);
            dfs(i, d, graph, v);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int source=0;
        int destination = graph.size()-1;
        vector<int> v={0};
        for(int i=0; i<1; i++)
        {
            dfs(i, destination, graph, v);
        }
        return ans;
    }
};