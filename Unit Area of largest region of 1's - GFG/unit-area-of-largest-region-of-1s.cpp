//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    bool isvalid(int i , int j, int n, int m, vector<vector<int>>& grid)
    {
        if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1)
            return true;
        else
            return false;
    }
    
    void dfs(int i , int j, int n, int m, vector<vector<int>>& grid, int &area)
    {
        area++;
        grid[i][j] = 0;
        if(isvalid(i+1, j, n, m, grid))
            dfs(i+1, j, n, m , grid, area);
            
        if(isvalid(i+1, j-1, n, m , grid))
            dfs(i+1, j-1, n, m , grid, area);
            
        if(isvalid(i+1, j+1, n, m , grid))
            dfs(i+1, j+1, n, m , grid, area);
            
        if(isvalid(i, j-1, n, m , grid))
            dfs(i, j-1, n, m , grid, area);
            
        if(isvalid(i, j+1, n, m , grid))
            dfs(i, j+1, n, m , grid, area);
            
        if(isvalid(i-1, j-1, n, m , grid))
            dfs(i-1, j-1, n, m , grid, area);
            
        if(isvalid(i-1, j, n, m , grid))
            dfs(i-1, j, n, m , grid, area);
            
        if(isvalid(i-1, j+1, n, m , grid))
            dfs(i-1, j+1, n, m , grid, area);
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    int area = 0;
                    dfs(i, j, n, m, grid, area);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends