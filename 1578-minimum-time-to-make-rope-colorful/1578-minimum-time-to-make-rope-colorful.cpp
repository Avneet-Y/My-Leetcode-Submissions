class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int time = 0;
        int mini;
        for(int i=1; i<n; i++)
        {
            if(colors[i] == colors[i-1])
            {
                mini = min(neededTime[i], neededTime[i-1]);
                time += mini;
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
                // We wanna maintain the current maximum neededTime. Agar same color group hai to maximum ko chor ke sabko htana pdega
            }
        }
        
        return time;
    }
};