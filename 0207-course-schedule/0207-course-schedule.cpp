//basically topological sort
/*

class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> indegree(numCourses, 0);
        vector<int> adj[numCourses];
        
        for(auto it : prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        
        //using BFS, this all below is topological sort in DAG
        
        
        for(int i=0; i<numCourses; i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if(count == numCourses)
            return true;
        return false;
        
    }
};
*/

//basically topological sort
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int> &st)
    {
        visited[node] = 1;
        for(auto it : adj[node])
        {
            if(visited[it] == 0)
                dfs(it, adj, visited, st);
        }
        st.push(node);
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);
        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        stack<int> st;
        
        for(int i=0; i<numCourses; i++)
        {
            if(visited[i] == 0)
            {
                dfs(i, adj, visited, st); 
            }
        }
        int ct = 0;
        vector<int> ans(numCourses, -1);
        while(!st.empty())
        {
            int t = st.top();
            st.pop();
            ans[t] = ct;
            ct++;
        }
        for(int i=0; i<numCourses; i++)
        {
            for(auto it : adj[i])
            {
                if(ans[i] >= ans[it])
                    return false;
            }
        }
        return true;
    }
};