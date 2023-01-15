/*

class Solution {
public:
    bool isvalid(int i, int j, int n, int m, vector<vector<int>>& vec, int color, int oldcolor)
    {
        if(i >= 0 and i < n and j >= 0 and j < m and vec[i][j] == oldcolor && vec[i][j] != color)
            return true;
        else
            return false;
    }
    
    void dfs(int i, int j, int n, int m, vector<vector<int>>& vec, int color, int oldcolor)
    {
        vec[i][j] = color;
        
        if (isvalid(i+1, j, n, m, vec, color, oldcolor))
            dfs(i+1, j, n, m, vec, color, oldcolor);
        
        if (isvalid(i, j+1, n, m, vec, color, oldcolor))
            dfs(i, j+1, n, m, vec, color, oldcolor);
        
        if (isvalid(i-1, j, n, m, vec, color, oldcolor))
            dfs(i-1, j, n, m, vec, color, oldcolor);
        
        if (isvalid(i, j-1, n, m, vec, color, oldcolor))
            dfs(i, j-1, n, m, vec, color, oldcolor);
        }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vec = image;
        int oldcolor = vec[sr][sc];
        dfs(sr, sc, n, m, vec, color, oldcolor);
        return vec;
    }
};

*/
//Another way for dfs

class Solution {
public:
    
    void dfs(int row, int col, vector<vector<int>>& vec, int color, int oldcolor, int delrow[], int delcol[])
    {
        vec[row][col] = color;
        int n = vec.size();
        int m = vec[0].size();
        for(int i=0; i<4; i++)
        {
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
               vec[nrow][ncol] == oldcolor && vec[nrow][ncol] != color)
            {
                dfs(nrow, ncol, vec, color, oldcolor, delrow, delcol);
            }
        }
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vec = image;
        int oldcolor = vec[sr][sc];
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        dfs(sr, sc, vec, color, oldcolor, delrow, delcol);
        return vec;
    }
};
