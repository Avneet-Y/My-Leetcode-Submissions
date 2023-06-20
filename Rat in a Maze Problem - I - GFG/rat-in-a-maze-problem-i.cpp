//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool issafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &m)
    {
        if(x >= 0 && x < n && y >= 0 && y<n && visited[x][y] == 0 && m[x][y] == 1)
            return true;
        return false;
    }
    
    void solve(vector<vector<int>> &m, int n, vector<string> &ans, vector<vector<int>> visited, 
                    string path, int x, int y)
    {
        if(x == n-1 && y == n-1)
        {
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        //down
        int xcor = x+1;
        int ycor = y;
        if(issafe(xcor, ycor, n, visited, m) == true)
        {
            path.push_back('D');
            solve(m, n, ans, visited, path, xcor, ycor);
            path.pop_back();
        }
        //left
        xcor = x;
        ycor = y-1;
        if(issafe(xcor, ycor, n, visited, m) == true)
        {
            path.push_back('L');
            solve(m, n, ans, visited, path, xcor, ycor);
            path.pop_back();
        }
        
        //right
        xcor = x;
        ycor = y+1;
        if(issafe(xcor, ycor, n, visited, m) == true)
        {
            path.push_back('R');
            solve(m, n, ans, visited, path, xcor, ycor);
            path.pop_back();
        }
        
        //Up
        xcor = x-1;
        ycor = y;
        if(issafe(xcor, ycor, n, visited, m) == true)
        {
            path.push_back('U');
            solve(m, n, ans, visited, path, xcor, ycor);
            path.pop_back();
        }
        visited[x][y] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        
        vector<vector<int>> visited(n, vector<int> (n, 0));
        
        int startx = 0;
        int starty = 0;
        string path = "";
        
        if(m[0][0] == 0)
            return ans;
        
        solve(m, n, ans, visited, path, startx, starty);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends