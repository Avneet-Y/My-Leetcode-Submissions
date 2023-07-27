class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int n = timeSeries.size()-1;
        for(int i=0; i<n; i++)
        {
            if(timeSeries[i] + duration < timeSeries[i+1])
            {
                ans += duration;
            }
            else
                ans += timeSeries[i+1] - timeSeries[i];
        }
        return ans+duration;
    }
};