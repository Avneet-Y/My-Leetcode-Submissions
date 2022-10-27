class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> vec1, vec2;

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if (img1[i][j] == 1)
                {
                    vec1.push_back({i, j});
                }
                if (img2[i][j] == 1)
                {
                    vec2.push_back({i, j});
                }
            }   
        }
        int ans = 0;
        map<pair<int, int>, int> mp;  
        for(auto i : vec1)
        {
            for(auto j : vec2)
            {
                mp[{i.first - j.first, i.second - j.second}]++;
                ans = max(ans, mp[{i.first - j.first, i.second - j.second}]);
            }
        }
        return ans;
    }
};