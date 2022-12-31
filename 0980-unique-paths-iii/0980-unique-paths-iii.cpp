class Solution {
public:
     int path(int i, int j, int n, int m, int &c, int count, vector<vector<int>> &grid)
     {
        if(i < 0 || j<0 || i >= n || j >= m || grid[i][j] == -1 || grid[i][j] == 3)
            return 0;
        
        if(grid[i][j] == 2)     // ending square
        {
            if(count - 1 == c)       //if all empty cells visited then returning 1 else 0 
                return 1;
            return 0;
        }
        
        grid[i][j] = 3;                                          // mark as visited
        
        int up = path(i - 1, j, n, m, c, count + 1, grid);  //possible paths
        int down = path(i + 1 , j, n, m, c, count + 1, grid);
        int left = path(i, j - 1, n, m, c, count + 1, grid);
        int right = path(i, j + 1, n, m, c, count + 1, grid);
    
        grid[i][j]=0;                                          // mark as unvisited
        
        return up + down + left + right;        // total count of reaching ending square
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int start, end;
        int c = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)   // if it is starting square
                {
                    start = i;
                    end = j;
                }
                
                if(grid[i][j] == 0)   // empty cells count
                {
                    c++;
                }
            }
        }
        return path(start, end, n, m, c, 0, grid);
    }
};