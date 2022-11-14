class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& stones, int ind, vector<bool>& visited) 
    {
        visited[ind] = true;
        for(int i = 0; i<n; i++) 
        {
            if(!visited[i] && ((stones[i][0] == stones[ind][0]) || (stones[i][1] == stones[ind][1]))) {
                dfs(stones, i, visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        vector<bool> visited(n, false);
        
        int count = 0;
        for(int i = 0; i<n; i++) 
        {
            if(visited[i])
                continue;
            dfs(stones, i, visited);
            count++;
        }
        return n - count;    
    }
};