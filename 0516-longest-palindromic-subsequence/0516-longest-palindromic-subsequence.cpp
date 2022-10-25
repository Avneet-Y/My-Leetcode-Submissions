class Solution {
public:
    int lcs(string str1, string str2, int m, int n)
    {
        int dp[m+1][n+1];
        for(int i = 0; i < m+1; i++)
        {
            for(int j = 0; j < n+1; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    
    int longestPalindromeSubseq(string s) {
       
        int m = s.size();
        string str2 = "";
        // reverse(str2.begin(), str2.end());
        for(int i = m; i >= 0; i--)
            str2.push_back(s[i]);
        int n = str2.size();
        int ans = lcs(s, str2, m, n);
        return ans;
        
    }
};