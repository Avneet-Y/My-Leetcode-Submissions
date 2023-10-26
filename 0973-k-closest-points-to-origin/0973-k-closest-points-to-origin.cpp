class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int,int>>> maxh;
        for(int i=0; i<n; i++)
        {
            int dis = points[i][1]*points[i][1] + points[i][0]*points[i][0];
            maxh.push({dis, {points[i][0], points[i][1]}});
            while(maxh.size() > k)
            {
                maxh.pop();
            }
        }
        while(maxh.size() > 0)
        {
            ans.push_back({maxh.top().second.first, maxh.top().second.second});
            maxh.pop();
        }
        return ans;
    }
};