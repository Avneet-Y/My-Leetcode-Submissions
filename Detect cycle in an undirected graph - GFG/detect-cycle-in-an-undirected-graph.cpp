//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int src, int vis[], vector<int> adj[])
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(q.size() > 0)
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjacentnode : adj[node])
            {
                if(vis[adjacentnode] == 0)
                {
                    vis[adjacentnode] = 1;
                    q.push({adjacentnode, node});
                }
                else if(parent != adjacentnode)
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        for(int i=0; i<V; i++)
        {
            if(vis[i] == false)
            {
                if(bfs(i, vis, adj) == true)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends