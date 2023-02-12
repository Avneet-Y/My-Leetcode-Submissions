class Solution {
public:
    
    long long ans;
    long long solve(vector<vector<int>> &adj, vector<int> &vis, int node, int seats){

       vis[node] = 1;
       long long ct = 1;  // people at each node
        for(auto it :adj[node])
        {
            if(!vis[it])
            {
                ct += solve(adj,vis,it,seats);
            }
        }
        long long x = ct/seats;  
        if(ct % seats)
        {  
            x++;    //people are more than the seats
        }
        if(node != 0)
        { 
            ans += x;  // not a goal state then add total no cars to the ans
        }
          return ct;  // people at particular node
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        if(n == 0)
        {
            return 0;
        }
        ans = 0;
        vector<vector<int>> adj(n+1);  //store in adj matrix 
        for(int i=0; i<n; i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        vector<int> vis(n+1, 0);  
        solve(adj, vis, 0, seats);
        return ans;
        
    }
};