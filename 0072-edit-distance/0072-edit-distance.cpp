class Solution {
public:
    
    int lcs(string s1, string s2, int n, int m)
    {
        int dp[n+1][m+1];
        for(int i = 0; i<n+1; i++)
        {
            dp[i][0] = i;
        }
        for(int j = 0; j<m+1; j++)
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
                    dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
            }
        }
        return dp[n][m];
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int ans = lcs(word1, word2, n, m);
        return ans;
    }
};