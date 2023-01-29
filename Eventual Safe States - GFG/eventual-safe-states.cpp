//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// class Solution {
//   public:
//   bool dfscheck(int node, vector<int> adj[], int visited[], int pathvis[], int check[])
//   {
//       visited[node] = 1;
//       pathvis[node] = 1;
//       check[node] = 0;
      
//       for(auto it : adj[node])
//       {
//           if(visited[it] == 0)
//           {
//               if(dfscheck(it, adj, visited, pathvis, check) == true)
//               {
//                   check[node] = 0;
//                   return true;
//               }
//           }
//           else if(pathvis[it] == 1)
//           {
//                   check[node] = 0;
//                   return true;
//           }
//       }
      
//       check[node] = 1;
//       pathvis[node] = 0;
//       return false;
//   }
  
//     vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
//         // code here
//         int visited[V] = {0};
//         int pathvis[V] = {0};
//         int check[V] = {0};
//         vector<int> safenode;
//         for(int i=0; i<V; i++)
//         {
//             if(visited[i] == 0)
//             {
//                 dfscheck(i, adj, visited, pathvis, check);
//             }
//         }
//         for(int i=0; i<V; i++)
//         {
//             if(check[i] == 1)
//             {
//                 safenode.push_back(i);
//             }
//         }
//         return safenode;
//     }
// };

class Solution {
  public:
  bool dfscheck(int node, vector<int> adj[], int visited[], int pathvis[])
  {
      visited[node] = 1;
      pathvis[node] = 1;
      
      for(auto it : adj[node])
      {
          if(visited[it] == 0)
          {
              if(dfscheck(it, adj, visited, pathvis) == true)
              {
                  pathvis[node] = 1;
                  return true;
              }
          }
          else if(pathvis[it] == 1)
          {
                  pathvis[node] = 1;
                  return true;
          }
      }
      
      pathvis[node] = 0;
      return false;
  }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int visited[V] = {0};
        int pathvis[V] = {0};
        
        vector<int> safenode;
        for(int i=0; i<V; i++)
        {
            if(visited[i] == 0)
            {
                dfscheck(i, adj, visited, pathvis);
            }
        }
        for(int i=0; i<V; i++)
        {
            if(pathvis[i] == 0)
            {
                safenode.push_back(i);
            }
        }
        return safenode;
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