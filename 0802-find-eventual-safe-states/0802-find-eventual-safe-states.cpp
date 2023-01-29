class Solution {
public:
    bool dfscheck(int node, vector<vector<int>>& graph, vector<int> &visited, vector<int> & pathvisited, vector<int> &check)
  {
      visited[node] = 1;
      pathvisited[node] = 1;
      check[node] = 0;
      
      for(auto it : graph[node])
      {
          if(visited[it] == 0)
          {
              if(dfscheck(it, graph, visited, pathvisited, check) == true)
              {
                  check[node] = 0;
                  return true;
              }
          }
          else if(pathvisited[it] == 1)
          {
                  check[node] = 0;
                  return true;
          }
      }
      
      check[node] = 1;
      pathvisited[node] = 0;
      return false;
  }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> visited(n, 0);
        vector<int> pathvisited(n, 0);
        vector<int> check(n, 0);
        
        vector<int> safenode;
        
        for(int i=0; i<n; i++)
        {
            if(visited[i] == 0)
            {
                dfscheck(i, graph, visited, pathvisited, check);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(check[i] == 1)
            {
                safenode.push_back(i);
            }
        }
        return safenode;
    }
};