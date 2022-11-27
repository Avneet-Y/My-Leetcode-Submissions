class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
		vector<vector<int>> job;
		vector<int> dp(n+1,0);
		for(int i=0;i<n;i++) job.push_back({startTime[i], endTime[i], profit[i]});  
		sort(job.begin(), job.end());
		sort(startTime.begin(), startTime.end());
		for(int i=n-1; i>=0; i--)
        {
			int ind = lower_bound(startTime.begin(),startTime.end(),job[i][1])-startTime.begin();
			int pick = job[i][2] + dp[ind];
			int notpick = dp[i+1];
			dp[i] = max(pick, notpick);
		}
		return dp[0];
    }
};