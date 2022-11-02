class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int diff1, diff2;
        int ans = 0;

        for(int i = 1; i < n; i++)
        {
            diff1 = abs(points[i][0] - points[i - 1][0]);
            diff2 = abs(points[i][1] - points[i - 1][1]);
            ans = ans + max(diff1, diff2);
        }
        return ans;
    }
};