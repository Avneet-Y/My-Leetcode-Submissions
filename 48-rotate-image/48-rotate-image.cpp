// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int A;
      
//          for(int i=1;i<=n;i++)
//         {
//             for(int j=n;j>=1;j--)
//             { 
//                 cout<<matrix[j][i];
//             }
            
//         }
//                
//     }
// };




// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int A;
      
//          for(int i=1;i<=n;i++)
//         {
//             for(int j=n;j>=1;j--)
//             { 
//                 A = matrix[j][i];
//                 matrix[j][i] = matrix[i][j];
//                 matrix[i][j] = A;
//             }
            
//         }
//          for (int i = 1; i <= n; i++)
//             reverse(matrix[i].begin(), matrix[i].end());        
//     }
// };


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int A;

        for (int  i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                A = matrix[i][j];       //transpose
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = A;
             }       
        }
        //after transpose then reverse
        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
        
    }
};