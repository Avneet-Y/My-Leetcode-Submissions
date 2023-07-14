class Solution {
public:
    bool isvalid(vector<vector<int>>& vec, int i, int j, int n, int m, int oldcolor, int newcolor)
    {
        if(i>=0 && i<n && j>=0 && j<m && vec[i][j] == oldcolor && vec[i][j] != newcolor)
            return true;
        return false;
        
    }
    void dfs(vector<vector<int>>& vec, int i, int j, int n, int m, int oldcolor, int newcolor)
    {
        vec[i][j] = newcolor;
        
        if(isvalid(vec, i+1, j, n, m, oldcolor, newcolor))
            dfs(vec, i+1, j, n, m, oldcolor, newcolor);
        
        if(isvalid(vec, i-1, j, n, m, oldcolor, newcolor))
            dfs(vec, i-1, j, n, m, oldcolor, newcolor);
        
        if(isvalid(vec, i, j+1, n, m, oldcolor, newcolor))
            dfs(vec, i, j+1, n, m, oldcolor, newcolor);
        
        if(isvalid(vec, i, j-1, n, m, oldcolor, newcolor))
            dfs(vec, i, j-1, n, m, oldcolor, newcolor);
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vec = image;
        int oldcolor = vec[sr][sc];
        dfs(vec, sr, sc, n, m, oldcolor, color);
        return vec;
    }
};