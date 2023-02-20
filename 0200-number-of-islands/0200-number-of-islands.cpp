class Solution {
public:
    bool isvalid(vector<vector<char>>& grid, int i, int j, int n, int m)
    {
        if(i >= 0 && i < n && j >= 0 && j<m && grid[i][j] == '1')
            return true;
        return false;
    }
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m)
    {
        grid[i][j] = '0';
        if(isvalid(grid, i+1, j, n, m))
            dfs(grid, i+1, j, n, m);
        
        if(isvalid(grid, i-1, j, n, m))
            dfs(grid, i-1, j, n, m);
        
        if(isvalid(grid, i, j+1, n, m))
            dfs(grid, i, j+1, n, m);
        
        if(isvalid(grid, i, j-1, n, m))
            dfs(grid, i, j-1, n, m);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        return count;
        
    }
};