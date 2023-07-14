//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   void dfs(int node, vector<int> adjLis[], vector<int> &visited)
    {
        visited[node] = 1;
        for(auto it : adjLis[node])
        {
            if(visited[it] == 0)
                dfs(it, adjLis, visited);
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int ans = 0;
        
        vector<int> adjLis[V];
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(adj[i][j] == 1 && i != j)
                {
                    adjLis[j].push_back(i);
                    adjLis[i].push_back(j);
                }
            }
        }
        vector<int> visited(V, 0);
        
        for(int i=0; i<V; i++)
        {
            if(visited[i] != 1)
            {
                ans++;
                dfs(i, adjLis, visited);
            }
        }
        return ans; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends