class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(m);

        for(int j = 0; j < m; j++) 
        {
            int currpos = j;
            int newpos = -1;
            for(int i = 0; i < n; i++)
            {
                newpos = currpos + grid[i][currpos];
                
                if(newpos < 0 || newpos >= m || grid[i][currpos] != grid[i][newpos])
                {
                    currpos = -1;
                    break;
                }
                currpos = newpos;
            }
            ans[j] = currpos;
        }
        return ans;
    }
};