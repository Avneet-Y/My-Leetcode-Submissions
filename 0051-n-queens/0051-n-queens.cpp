class Solution {
public:
    bool issafe(int row, int col, int n, vector<string> &boards)
    {
        int temprow = row;
        int tempcol = col;
        
        while(row >= 0 && col >= 0)
        {
            if(boards[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }
        col = tempcol;
        row = temprow;
        
        while(col >= 0)
        {
            if(boards[row][col] == 'Q')
            {
                return false;
            }
            col--;
        }
        col = tempcol;
        row = temprow;
        
        while(row < n && col >= 0)
        {
            if(boards[row][col] == 'Q')
            {
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    
    void solve(int n, vector<vector<string>> &ans, vector<string> &boards, int col)
    {
        if(col == n)
        {
            ans.push_back(boards);
            return;
        }
        for(int row=0; row<n; row++)
        {
            if(issafe(row, col, n, boards) == true)
            {
                boards[row][col] = 'Q';
                solve(n, ans, boards, col+1);
                boards[row][col] = '.';
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
        solve(n, ans, boards, 0);
        return ans;     
    }
};