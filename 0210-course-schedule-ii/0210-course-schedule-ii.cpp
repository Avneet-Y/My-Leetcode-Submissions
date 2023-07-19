class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n, 0);
        
        // for(int i=0; i<n; i++)
        //     indegree[i] = 0;
        
        vector<int> topolog;
        vector<int> adj[n];
        
        for(auto it: prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0; i<n; i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topolog.push_back(node);
            
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        
        if(topolog.size() == n)
            return topolog;
        return {};
    }
};