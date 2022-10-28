class Solution {
public:
    int dp[2001][2001];
    bool ispalindrome(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string &s, int i, int j)
    {
        if(i >= j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int mini = INT_MAX; 
        
        if(ispalindrome(s, i, j) == true)
            return 0;
        
        for(int k = i; k <= j-1; k++)
        {
            if(ispalindrome(s, i, k))
            {
                int tempans = solve(s, k+1, j) + 1;
                mini = min(mini, tempans);
                dp[i][j] = mini;
            }
        }
        return mini;
    }
    
    int minCut(string s) {
        int ans;
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        ans = solve(s, 0, n-1);
        return ans;
        
    }
};