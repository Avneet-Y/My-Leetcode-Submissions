//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& board, int delrow[], int delcol[])
    {
        int n = board.size();
        int m = board[0].size();
        visited[row][col] = 1;
        
        for(int i=0; i<4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >=0 && nrow<n && ncol >=0 && ncol < m && visited[nrow][ncol] == 0 && board[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, visited, board, delrow, delcol);
            }
        }
    }
    
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        for(int j = 0; j < m; j++)
        {
            if(!visited[0][j] && mat[0][j] == 'O')  //1st row
            {
                dfs(0, j, visited, mat, delrow, delcol);
            }
            if(!visited[n-1][j] && mat[n-1][j] == 'O')  //last row
            {
                dfs(n-1, j, visited, mat, delrow, delcol);
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i][0] && mat[i][0] == 'O')  //1st col
            {
                dfs(i, 0, visited, mat, delrow, delcol);
            }
            if(!visited[i][m-1] && mat[i][m-1] == 'O')  //last col
            {
                dfs(i, m-1, visited, mat, delrow, delcol);
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!visited[i][j] && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        } 
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends