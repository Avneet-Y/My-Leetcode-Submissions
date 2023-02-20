class Solution {
public:
    void bfs(int row, int col, int n, int m, vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
      
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(ncol >= 0 && ncol < m && nrow >= 0 && nrow < n && visited[nrow][ncol] == 0 && grid[nrow][ncol] == '1')
                {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> visited(n , vector<int> (m, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1' && visited[i][j] == 0)
                {
                    count++;
                    bfs(i, j, n, m, grid, visited);
                }
            }
        }
        return count;
        
    }
};