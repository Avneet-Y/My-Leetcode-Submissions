//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited, int delrow[], int delcol[] )
  {
      int n = grid.size();
      int m = grid[0].size();
      visited[row][col] = 1;
      for(int i = 0; i<4; i++)
      {
          int nrow = row + delrow[i];
          int ncol = col + delcol[i];
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
          {
              dfs(nrow, ncol, grid, visited, delrow, delcol);
          }
      }
  }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int count = 0;
        
        for(int j=0; j<m; j++)   
        {
            if(grid[0][j] == 1 && !visited[0][j])   //first row
            {
                dfs(0, j, grid, visited, delrow, delcol);
            }
            if(grid[n-1][j] == 1 && !visited[n-1][j])  //last row
            {
                dfs(n-1, j, grid, visited, delrow, delcol);
            }
        }
        
        for(int i=0; i<n; i++)   
        {
            if(grid[i][0] == 1 && !visited[i][0])   //first col
            {
                dfs(i, 0, grid, visited, delrow, delcol);
            }
            if(grid[i][m-1] == 1 && !visited[i][m-1])  //last col
            {
                dfs(i, m-1, grid, visited, delrow, delcol);
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1 and visited[i][j] == 0)
                {
                    grid[i][j] = 0;
                    count++;
                }
            }
        }
        return count;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends