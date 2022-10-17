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