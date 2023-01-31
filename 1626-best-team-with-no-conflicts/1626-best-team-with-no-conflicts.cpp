/*
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++)
        {
            vec.push_back({ages[i], scores[i]});
        }
        sort(vec.begin(), vec.end());
        vector<int> dp(n);
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            dp[i] = vec[i].second;
            for(int j = 0; j < i; j++)
             {
                if(vec[j].second <= vec[i].second)
                    dp[i] = max(dp[i], dp[j] + vec[i].second);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
*/


class Solution {
public:
int dp[1001][1001];
    int rec(vector<pair<int,int>>& vec, int i, int prev, int age)
    {
        if(i >= vec.size())
            return 0;

        if(dp[i][prev+1] != -1)
            return dp[i][prev+1];
        
        int take = 0, notTake = 0;
        if(prev == -1 || vec[i].second >= vec[prev].second)
        {
            take = vec[i].second + rec(vec, i+1, i, vec[i].first);
        }
        notTake = rec(vec, i+1, prev, vec[i].first);
        return dp[i][prev+1] = max(notTake, take);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        memset(dp, -1, sizeof(dp));
        vector<pair<int,int>> vec;
        int n = scores.size();
        for(int i=0; i<n; i++)
        {
            vec.push_back({ages[i],scores[i]});
        }
        sort(vec.begin(),vec.end());
        return rec(vec, 0, -1, vec[0].first);
    }
};