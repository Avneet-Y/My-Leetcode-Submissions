// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m=matrix.size();
//         int n=matrix[0].size();
//         for(int i=0; i<m; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 if(matrix[i][j]==target)
//                     return true;
//             }
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0, j=n-1;
        while(i<m && j>=0)
        {
            int present = matrix[i][j];
            if(present == target)
                return true;
            if(target > present)
                i++;
            else
                j--;
        }
        return false;
    }
};