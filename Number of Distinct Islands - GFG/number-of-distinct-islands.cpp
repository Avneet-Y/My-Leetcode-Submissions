//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  void dfs(int row, int col, vector<pair<int, int>> &vec, vector<vector<int>>& grid, 
  vector<vector<int>> &visited, int baserow, int basecol)
  {
      visited[row][col] = 1;
      int n = grid.size();
      int m = grid[0].size();
      vec.push_back({row-baserow, col-basecol});
      
      int delrow[] = {1,-1,0,0};
      int delcol[] = {0,0,-1,1}; 
      for(int i=0; i<4; i++)
      {
          int nrow = row + delrow[i];
          int ncol = delcol[i] + col;
          
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
          {
              dfs(nrow, ncol, vec, grid, visited, baserow, basecol);
          }
      }
  }
 
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1 && visited[i][j] == 0)
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, vec, grid, visited, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends