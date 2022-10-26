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
    
    int minInsertions(string s) {
        
        int m = s.size();
        string st2 = s;
        reverse(s.begin(), s.end());
        int ans, lcslen;
        lcslen = lcs(s, st2, m, m);
        ans = m - lcslen;
        return ans;
    }
};