//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool dfs(int node, int visited[], int path[], int check[], vector<int> adj[])
  {
      visited[node] = 1;
      path[node] = 1;
      check[node] = 0;
      
      for(auto it : adj[node])
      {
          if(visited[it] == 0)
          {
              if(dfs(it, visited, path, check, adj) == true)
              {
                  check[node] = 0;
                  return true;
              }
          }
          else if(path[it] == 1)
          {
              check[node] = 0;
              return true;
          }
      }
      path[node] = 0;
      check[node] = 1;
      return false;
      
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> ans;
        int visited[V] = {0};
        int path[V] = {0};
        int check[V] = {0};
        
        for(int i=0; i<V; i++)
        {
           dfs(i, visited, path, check, adj);
    
        }
        for(int i=0; i<V; i++)
        {
            if(check[i] == 1)
                ans.push_back(i);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends