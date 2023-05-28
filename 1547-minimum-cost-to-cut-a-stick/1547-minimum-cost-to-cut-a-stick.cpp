class Solution {
public:
    int len;
    int solve(int n,int st,int end,vector<int>&cuts,vector<vector<int>>&dp)
    {   
        if(st >= end)
            return 0;
    
        if(dp[st][end] != 0)
            return dp[st][end];
        int ans = INT_MAX;

        for(int i=st; i<end; i++)
        {

            int lt = 0, rt = 0;
            if(st == 0)
                lt = 0;
            else
                lt = cuts[st-1];
            if(end == cuts.size())
                rt = len;
            else
                rt = cuts[end];

            int cost = rt-lt;
            int left = solve(lt, st, i, cuts, dp);
            int right = solve(rt, i+1, end, cuts, dp);

            int tempans = left+right+cost;
            ans = min(ans,tempans);
    }

    return dp[st][end] = ans;

}
    int minCost(int n, vector<int>& cuts) {
        int l = cuts.size();
        vector<vector<int>> dp(l+1,vector<int>(l+1, 0));
        len = n;
        sort(cuts.begin(),cuts.end());
        return solve(n, 0, l, cuts, dp);
    }
};