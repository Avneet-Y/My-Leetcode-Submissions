//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool isvalid(vector<vector<int>>& vec, int i, int j, int n, int m, int oldcolor, int newColor)
    {
        if(i>=0 && i<n && j>=0 && j<m && vec[i][j] == oldcolor && vec[i][j] != newColor)
            return true;
        return false;
        
    }
    void dfs(vector<vector<int>>& vec, int i, int j, int n, int m, int oldcolor, int newColor)
    {
        vec[i][j] = newColor;
        
        if(isvalid(vec, i+1, j, n, m, oldcolor, newColor))
            dfs(vec, i+1, j, n, m, oldcolor, newColor);
        
        if(isvalid(vec, i-1, j, n, m, oldcolor, newColor))
            dfs(vec, i-1, j, n, m, oldcolor, newColor);
        
        if(isvalid(vec, i, j+1, n, m, oldcolor, newColor))
            dfs(vec, i, j+1, n, m, oldcolor, newColor);
        
        if(isvalid(vec, i, j-1, n, m, oldcolor, newColor))
            dfs(vec, i, j-1, n, m, oldcolor, newColor);
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vec = image;
        int oldcolor = vec[sr][sc];
        dfs(vec, sr, sc, n, m, oldcolor, newColor);
        return vec;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends