class Solution {
public:
    int solvelcs(string word1, string word2, int n1, int n2)
    {
        int dp[n1+1][n2+1];
        for(int i=0; i <= n1; i++)
        {
           dp[i][0] = i;
        }
        for(int j=0; j <= n2; j++)
        {
            dp[0][j] = j;
        }
        for(int i=1; i <= n1; i++)
        {
            for(int j=1; j <= n2; j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
        return dp[n1][n2];
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        int ans = solvelcs(word1, word2, n1, n2);
        return ans;
    }
};