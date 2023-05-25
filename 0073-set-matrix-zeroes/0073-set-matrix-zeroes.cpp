class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        map<int, bool> rowmp;
        map<int, bool> colmp;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    rowmp[i] = true;
                    colmp[j] = true;
                }
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(rowmp[i] == true || colmp[j] == true)
                    matrix[i][j] = 0;
            }
        }
        
    }
};