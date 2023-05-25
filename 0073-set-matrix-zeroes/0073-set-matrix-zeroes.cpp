class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool row1 = false;
        bool col1 = false;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(i == 0)
                        row1 = true;
                    if(j == 0)
                        col1 = true;
                    
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        if(col1 == true)
        {
            for(int i=0; i<m; i++)
                matrix[i][0] = 0;
        }
        if(row1 == true)
        {
            for(int j=0; j<n; j++)
                matrix[0][j] = 0;
        }
        
    }
};