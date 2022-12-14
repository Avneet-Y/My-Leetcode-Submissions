//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int solve(string s1, string s2, int n, int m)
    {
        int dp[n+1][m+1];
        for(int i=0; i<n+1; i++)
        {
            dp[i][0] = i;
        }
        for(int j=0; j<m+1; j++)
        {
            dp[0][j] = j;
        }
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
                                //ins                   //del           //replace
                }
            }
        }
        return dp[n][m];
    }
    
    int editDistance(string s, string t) {
        // Code here
        int n = s.size();
        int m = t.size();
        int ans;
        ans = solve(s, t, n, m);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends