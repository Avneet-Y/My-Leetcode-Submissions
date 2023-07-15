class Solution {
public:

    bool isvalid(int x, int y, int m, int n, char c, vector <vector<char>> &grid)
    {
        if(x<0 or x>=m or y<0 or y>=n) 
            return false;
        if(grid[x][y]!=c) 
            return false;
        return true;
    }
    
    bool detect(int x, int y, int px, int py, int m, int n,vector <vector <char>>&grid, vector<vector<int>> &visited){
        
       int dx[4] = {1,0,-1,0};
       int dy[4] = {0,1,0,-1};
       
	   if(visited[x][y]) 
           return true;
	 
        visited[x][y] = 1;
       
	   for(int i = 0; i<4; i++)
       {
            if(isvalid(x+dx[i], y+dy[i], m, n, grid[x][y], grid))
            {
                if((x+dx[i] != px or y+dy[i] != py) && detect(x+dx[i], y+dy[i], x, y, m, n, grid, visited)) 
                    return true;
            }
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector <vector <int>> visited (m,vector<int> (n,0));
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(!visited[i][j])
                {
                    if(detect(i, j, -1, -1, m, n, grid, visited)) 
                        return true;  
                }
            }
        }
        return false;
    }
};