class Solution {
public:
     int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> adj[n];
        unordered_map<int,int> ind;
        for(vector<int> &v : edges)
        {
            adj[v[0]].push_back(v[1]);
            ind[v[1]]++;
        }
        
        queue<int> q;
        vector<vector<int>> dp(n, vector<int> (26,0));
        for(int i=0; i<n; i++)
        {
            if(ind[i] == 0) 
            {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }
        
        int visited = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            visited++;
            for(int it : adj[node])
            {
                for(int i=0; i<26; i++)
                {
                   dp[it][i] = max(dp[it][i], dp[node][i] + (i == (colors[it] - 'a')));
                }

                ind[it]--;
                if(ind[it] == 0) 
                    q.push(it);
            }
        }
        
        if(visited < n) 
            return -1; 
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<26; j++)
            {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};