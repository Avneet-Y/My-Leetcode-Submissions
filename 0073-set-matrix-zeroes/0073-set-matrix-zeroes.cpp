class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
//         unordered_map<int, bool> rowmp;
//         unordered_map<int, bool> colmp;
        
//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<m; j++)
//             {
//                 if(matrix[i][j] == 0)
//                 {
//                     rowmp[i] = true;
//                     colmp[j] = true;
//                 }
//             }
//         }
        
//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<m; j++)
//             {
//                 if(rowmp[i] == true || colmp[j] == true)
//                 {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
        bool row1 = false;
        bool col1 = false;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(i == 0)
                    {
                        row1 = true;
                    }
                    if(j == 0)
                    {
                        col1 = true;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if(col1 == true)
        {
            for(int i=0; i<n; i++)
                matrix[i][0] = 0;
        }
        if(row1 == true)
        {
            for(int j=0; j<m; j++)
                matrix[0][j] = 0;
        }
        
        
    }
};