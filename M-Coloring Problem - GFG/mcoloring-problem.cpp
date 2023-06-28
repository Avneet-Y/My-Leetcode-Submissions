//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isvalid(int node, int color[],  bool graph[101][101], int n, int col)
    {
        for(int i=0; i<n; i++)
        {
            if(i!=node && graph[i][node] == 1 && color[i] == col)
            {
                return false;
            }
        }
        return true;
        
    }
    bool solve(int node, bool graph[101][101], int color[], int m, int n)
    {
        if(node == n)
        {
            return true;
        }
        
        for(int col = 1; col <= m; col++)  //col = color to be given
        {
            if(isvalid(node, color, graph, n, col) == true)
            {
                color[node] = col;
                if(solve(node+1, graph, color, m, n) == true)
                    return true;
                color[node] = 0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n] = {0};
        if(solve(0, graph, color, m, n) == true)
            return true;
        return false;
        
        // your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends