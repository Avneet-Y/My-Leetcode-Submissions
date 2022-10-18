/*

class Solution {
public:
     int dp[1001][1001];
     int lcs(string &X, string &Y, int n, int m){
        if(n==0 || m==0)
            return 0;
        if(dp[n][m] != -1)
            return dp[n][m];
        if(X[n-1] == Y[m-1])
            return dp[n][m] = 1 + lcs(X, Y, n-1, m-1);
        else
            return dp[n][m] = max(lcs(X, Y, n-1, m), lcs(X, Y, n, m-1));
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        int n = s1.size();
        int m = s2.size();
        return lcs(s1, s2, n, m);
    }   
};
*/


class Solution {
public:
  int lcsdp(string X, string Y, int n, int m){
    int dp[n+1][m+1];
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<m+1; j++)
        {
            if(i == 0 || j == 0) 
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(X[i-1] == Y[j-1]) 
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][m];
}
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        return lcsdp(s1, s2, n, m);
    }
};