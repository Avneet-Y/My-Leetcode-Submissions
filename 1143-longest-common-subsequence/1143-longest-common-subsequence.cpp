class Solution {
public:
    int lcs(string &text1, string &text2, int n1, int n2)
    {
        int dp[n1+1][n2+1];
        for(int i=0; i<n1+1; i++)
        {
            for(int j=0; j<n2+1; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                
            }
        }
        for(int i=1; i<n1+1; i++)
        {
            for(int j=1; j<n2+1; j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        
        int ans = 0;
        ans = lcs(text1, text2, n1, n2);
        return ans;
        
    }
};