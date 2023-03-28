class Solution {
public:
    int helper(int ind  , vector<int>&costs , unordered_set<int>&days,vector<int>&dp )
    {
        if(ind> 365)
        {
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
      
        if(days.find(ind) == days.end()) 
        {
        return helper(ind+1, costs, days, dp);
        }
    int day1 = costs[0] + helper(ind + 1, costs , days, dp);
    int day7 = costs[1] + helper(ind + 7, costs , days, dp);
    int day30 = costs[2] + helper(ind + 30, costs, days, dp );
    return dp[ind] = min(day1, min(day7, day30));
 }
 int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        unordered_set<int> temp;
        vector<int> dp(366,-1);
        for(int i = 0 ; i < n ; i++)
        {
           temp.insert(days[i]);
        }
       return helper(days[0], costs, temp, dp);
    }
};