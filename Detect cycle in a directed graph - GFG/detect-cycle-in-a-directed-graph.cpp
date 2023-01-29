//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfscheck(int node, vector<int> adj[], int visited[], int pathvisited[])
    {
        visited[node] = 1;
        pathvisited[node] = 1;
        for(auto it : adj[node])
        {
            if(visited[it] == 0)
            {
                if(dfscheck(it, adj, visited, pathvisited) == true)
                    return true;
            }
            else if(pathvisited[it] == 1)   //if node had been prev visited but it has to be visited on same path
            {
                return true;
            }
        }
        pathvisited[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int visited[V] ={0};
        int pathvisited[V] = {0};
        for(int i=0; i<V; i++)
        {
            if(visited[i] == 0)
            {
                if(dfscheck(i, adj, visited, pathvisited) == true)
                    return true;
            }
        }
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends