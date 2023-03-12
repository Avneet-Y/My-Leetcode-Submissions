class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        int n = points.size();
        priority_queue< pair<int, pair<int, int>> > maxh;
        for(int i=0; i<n; i++)
        {
            maxh.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], 
                       {points[i][0], points[i][1]}});
            if(maxh.size() > k)
                maxh.pop();
        }
        while(!maxh.empty())
        {
            pair<int, int> p = maxh.top().second;
            ans.push_back({p.first, p.second});
            maxh.pop();
        }
        return ans;
    }
};