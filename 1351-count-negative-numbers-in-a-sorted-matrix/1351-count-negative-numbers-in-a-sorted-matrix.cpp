class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int size = n*m-1;
        int count = 0;
        for(int i=0; i<=size; i++)
        {
            if(grid[i/m][i%m] < 0)
                count++;
        }
        
        return count;
    }
};