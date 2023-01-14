/*

class Solution {
public:
    
    bool isvalid(int i, int j, int n, int m, vector<vector<char>>& grid)
    {
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j]=='1')
            return true;
        else
            return false;
    }
    
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid)
    {
        grid[i][j] = '0';
        
        if (isvalid(i+1, j, n, m, grid))
            dfs(i+1, j, n, m, grid);
        
        if (isvalid(i, j+1, n, m, grid))
            dfs(i,j+1,n,m,grid);
        
        if (isvalid(i-1, j, n, m, grid))
            dfs(i-1, j, n, m, grid);
        
        if (isvalid(i, j-1, n, m, grid))
            dfs(i, j-1, n, m, grid);
        
        }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count1 = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1'){
                count1++;
                dfs(i,j,n,m,grid);
                }
            }
        }
        return count1;
    }
};

*/
class Solution {
public:    
    
    void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>>& grid)
    {
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        while(q.size() > 0)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int delrow = -1; delrow <= 1; delrow++)
            {
                for(int delcol = -1; delcol <= 1; delcol++)
                {
                    //not to check the diagonal elements.
                    if((delrow == -1 && delcol == -1) || (delrow == -1 && delcol == 1) 
                       || (delrow == 1 && delcol == -1) || (delrow == 1 && delcol == 1))
                    {
                        continue;
                    }
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                       && grid[nrow][ncol] == '1' && visited[nrow][ncol] == 0)
                    {
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});

                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> visited(n, vector<int> (m, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1' && visited[i][j] == 0)
                {
                    count++;
                    bfs(i, j, visited, grid);
                }
            }
        }
        return count; 
    }
};
