class Solution {
public:
     int dp[101];

    int numDecodings(string s) {
        memset(dp,0,sizeof dp);
        int n = s.size();
        if(s[0] == '0')
            return 0;
        if(n == 1)
            return 1;
        int i,j;
        dp[0] = 1;
        dp[1] = 1;
        for(i=2; i<=n; i++)
        {
            int one = s[i-1]-'0';
            string temp = s.substr(i-2,2);
             if(one>=1)
                dp[i] += dp[i-1];
            if(stoi(temp) >= 10 and stoi(temp) <= 26)
            {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};