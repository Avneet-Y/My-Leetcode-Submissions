class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size(), ct = 0;
        for(int i=0; i<n; i++)
        {
            unordered_map<double, int> mp;
            int yaxis = 0;
            for(int j=i+1; j<n; j++)
            {
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                if(dx==0)
                {
                    yaxis++;
                }
                else
                {
                    double slope = (double)dy/dx;
                    mp[slope]++;
                }
            }
            for(auto &it : mp)
            {
                ct = max(ct, it.second);
            }
            ct = max(ct, yaxis);
        }
        return ct+1;
    }
};