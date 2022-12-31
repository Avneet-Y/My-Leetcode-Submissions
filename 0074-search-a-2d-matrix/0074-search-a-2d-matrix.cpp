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

//O(m+n)
/*  class Solution {
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
*/

/*

//O(log(mn))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int start = 0, end = m*n - 1;
        while(start <= end)
        {
            int mid = start + (end -start)/2;
            if(matrix[mid / n][mid % n] == target)  //row index=[ele no.(from 0)/totalcols] 
                return true;                       //col index = [ele no. % total cols]
            if(matrix[mid / n][mid % n] < target)   //target in right side
                start = mid+1;
            else
                end = mid-1;                //target in left side
        }
        return false;
    }
};
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = m - 1;
        while(i >= 0 && i < n && j >= 0 && j < m)
        {
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                j--;
            else
                i++;
        }
        return false;
    }
};
