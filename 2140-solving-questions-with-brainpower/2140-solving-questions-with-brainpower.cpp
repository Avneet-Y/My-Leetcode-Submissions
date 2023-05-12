class Solution {
public:
    long long help(int ind, vector<vector<int>>&ques, vector<long long> &dp)
    {
        int n = ques.size();
        if(ind >= n )
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        long long notPick = help(ind + 1, ques, dp); 
        long long pick = ques[ind][0] + help(ind + ques[ind][1]+1, ques, dp);
        dp[ind] = max(pick, notPick);
        return dp[ind];
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return help(0, questions, dp);
        
    }
};