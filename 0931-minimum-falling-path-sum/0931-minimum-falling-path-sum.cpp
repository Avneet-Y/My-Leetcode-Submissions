class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>& matrix,int x,int y)
    {
        if(x == matrix.size())
            return 0;
        if(y < 0 || y == matrix[0].size())
            return INT_MAX;
        if(dp[x][y])
            return dp[x][y];
        else
            return dp[x][y] = matrix[x][y] + min(solve(matrix, x+1, y),                                        min(solve(matrix, x+1, y+1), solve(matrix, x+1, y-1)));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)
            return 0;
        int cols = matrix[0].size();
        int ans = INT_MAX;
        for(int j = 0; j<cols; j++)
        {
            ans = min(ans, solve(matrix, 0, j));
        }
        return ans;
    }
};