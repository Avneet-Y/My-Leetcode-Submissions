class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                }
            }
        }
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int ans = 0;
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop(); 
            
            for(int i=0; i<4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0)
                {
                    q.push({nrow, ncol});
                    grid[nrow][ncol] = grid[row][col] + 1;
                    ans = max(ans, grid[nrow][ncol]);
                }
            }
        }
        if(ans > 0) 
            return ans-1;
        return -1;        
    }
};