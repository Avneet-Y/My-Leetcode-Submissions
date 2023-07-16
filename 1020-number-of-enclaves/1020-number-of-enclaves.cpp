class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>>& grid, int delrow[], int delcol[])
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        
        for(int i=0; i<4; i++)
        {
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, visited, grid, delrow, delcol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;
        
        int delrow[] = {1, -1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        
        for(int i=0; i<n; i++)
        {
            if(visited[i][0] == 0 && grid[i][0] == 1)
                dfs(i, 0, visited, grid, delrow, delcol);
            if(visited[i][m-1] == 0 && grid[i][m-1] == 1)
                dfs(i, m-1, visited, grid, delrow, delcol);   
        }
        
        for(int j=0; j<m; j++)
        {
            if(visited[0][j] == 0 && grid[0][j] == 1)
                dfs(0, j, visited, grid, delrow, delcol);
            if(visited[n-1][j] == 0 && grid[n-1][j] == 1)
                dfs(n-1, j, visited, grid, delrow, delcol);
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1 && visited[i][j] == 0)
                {
                    // grid[i][j] = 1;
                    count++;
                }
            }
        }
        return count;
        
    }
};