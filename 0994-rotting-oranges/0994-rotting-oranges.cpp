class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair <pair <int, int>, int>> q;
        int visited[n][m];
        int time = 0;
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else
                    visited[i][j] = 0;
            }
        }
        
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t); 
            q.pop();
            for(int i=0; i<4; i++)
            {      
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && visited[nrow][ncol] == 0 )
                {
                    q.push({{nrow, ncol}, t+1});
                    visited[nrow][ncol] = 2;   
                }   
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(visited[i][j] != 2 and grid[i][j] == 1)
                    return -1;
            }
        }
        return time;
    }
};