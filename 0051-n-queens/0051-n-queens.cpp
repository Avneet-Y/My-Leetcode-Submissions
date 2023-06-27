class Solution {
public:
//     bool issafe(int row, int col, int n, vector<string> &boards)
//     {
//         int temprow = row;
//         int tempcol = col;
        
//         while(row >= 0 && col >= 0)
//         {
//             if(boards[row][col] == 'Q')
//                 return false;
//             row--;
//             col--;
//         }
//         row = temprow;
//         col = tempcol;
        
//         while(col >= 0)
//         {
//             if(boards[row][col] == 'Q')
//                 return false;
//             col--;
//         }
//         row = temprow;
//         col = tempcol;
        
//         while(row < n && col >= 0)
//         {
//             if(boards[row][col] == 'Q')
//                 return false;
//             row++;
//             col--;
//         }
//         return true;   
//     }
    
    void solve(int col, vector<vector<string>> &ans, vector<string> &boards, int n, vector<int> &leftrow, vector<int> &upperdiag, vector<int> &lowerdiag)
    {
        if(col == n)
        {
            ans.push_back(boards);
            return;
        }
        
        for(int row = 0; row<n; row++)
        {
            if(leftrow[row] == 0 && upperdiag[n-1+col-row] == 0 && lowerdiag[row+col]== 0)
            {
                boards[row][col] = 'Q';
                leftrow[row] = 1;
                upperdiag[n-1+col-row] = 1;
                lowerdiag[row+col] = 1;
                solve(col+1, ans, boards, n, leftrow, upperdiag, lowerdiag);
                boards[row][col] = '.';
                leftrow[row] = 0;
                upperdiag[n-1 + col-row] = 0;
                lowerdiag[row + col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> boards(n);
        string s(n, '.');
        for(int i=0; i<n; i++)
        {
            boards[i] = s;
        }
        vector<int> leftrow(n, 0); 
        vector<int> upperdiag(2*n - 1, 0);
        vector<int> lowerdiag(2*n - 1, 0);
        solve(0, ans, boards, n, leftrow, upperdiag, lowerdiag);
        return ans;
    }
};