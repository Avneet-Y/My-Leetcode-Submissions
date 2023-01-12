class Solution {
public:
    unordered_map<int, vector<int>> mp;

    int helper (vector<int> *adj, string &labels, int vertex, int target, vector<int>&res, int parent)
    {
        if(mp.find (vertex) != mp.end ()) 
            return mp[vertex][target]; 
        if((adj[vertex].size()==1 && adj[vertex][0] == parent) || adj[vertex].size()==0)
        {
            res[vertex] = 1;
            if (target == (labels[vertex]-'a')) 
                return 1;
            return 0;
        }

        vector<int> hash (26);
        for (int i = 0; i < 26; i++)
        {
            int ans = 0;
            if (i == (labels[vertex]-'a')) 
                ans++;

            for (auto x: adj[vertex])
            {
                if (parent != x)
                ans += helper (adj, labels, x, i, res, vertex);
            }
            hash[i] = ans;
        }

        mp[vertex] = hash;
        res[vertex] = hash[labels[vertex]-'a'];

        if (target == -1) 
            return{};       
        return hash[target];
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> res (n); 
        vector<int> adj [n];

        for (int i = 0; i < edges.size (); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        helper (adj, labels, 0, -1, res, 0);
        return res;
    }
};