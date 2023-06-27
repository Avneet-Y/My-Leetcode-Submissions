class Solution {
public:
    bool issafe(int row, int col, int n, vector<string> &boards)
    {
        int temprow = row;
        int tempcol = col;
        
        while(row >= 0 && col >= 0)
        {
            if(boards[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        row = temprow;
        col = tempcol;
        
        while(col >= 0)
        {
            if(boards[row][col] == 'Q')
                return false;
            col--;
        }
        row = temprow;
        col = tempcol;
        
        while(row < n && col >= 0)
        {
            if(boards[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;   
    }
    
    void solve(int col, vector<vector<string>> &ans, vector<string> &boards, int n)
    {
        if(col == n)
        {
            ans.push_back(boards);
            return;
        }
        
        for(int row = 0; row<n; row++)
        {
            if(issafe(row, col, n, boards) == true)
            {
                boards[row][col] = 'Q';
                solve(col+1, ans, boards, n);
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
        solve(0, ans, boards, n);
        return ans;
    }
};