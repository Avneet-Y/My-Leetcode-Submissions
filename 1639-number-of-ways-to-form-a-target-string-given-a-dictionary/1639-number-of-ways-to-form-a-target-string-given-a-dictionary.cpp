class Solution {
public: 
    long long MOD = 1000000007;
    int solve(vector<vector<int>> &freq, string &target, vector<vector<int>> &dp, int col, int targetind)
    {
        if (targetind == target.size()) 
        {
            return 1; 
        }
        if (col == freq[0].size()) 
        {
            return 0;  
        }
        if (dp[col][targetind] != -1) 
        {
            return dp[col][targetind];
        }
        
        int targetCh = target[targetind] - 'a';
        int notPick = solve(freq, target, dp, col + 1, targetind);
        
        int pick = 0;
        if (freq[targetCh][col] != 0)
        {
            int currWays = freq[targetCh][col];
            int nextWays = solve(freq, target, dp, col + 1, targetind + 1);
            pick = (currWays % MOD * nextWays % MOD) % MOD;
        }
        
        return dp[col][targetind] = (pick % MOD + notPick % MOD) % MOD;
        
    }
    int numWays(vector<string>& words, string target) 
    {
        int m = words.size();
        int n = words[0].size();
        vector<vector<int>> freq(26, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                freq[words[i][j] - 'a'][j]++; //freq of 'ch' in jth col
            }
        }
        vector<vector<int>> dp(n, vector<int>(target.size(), -1));
        int ans = solve(freq, target, dp, 0, 0);
        return ans;
    }
};