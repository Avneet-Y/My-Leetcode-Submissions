class DisjointSet {
    vector<int> parent; 
    vector<int> rank;
    public:
    DisjointSet(int n) {
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    int findUParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    
    void unionByRank(int u, int v) {
        int uparentU = findUParent(u);
        int uparentV = findUParent(v);
        
        if(rank[uparentU] > rank[uparentV]) {
            parent[uparentV] = uparentU;

        } else if(rank[uparentU] < rank[uparentV]){
            parent[uparentU] = uparentV;

        } else {
            parent[uparentU] = uparentV;
            rank[uparentV]++;
        }       
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n), bob(n);
        
        int removed_edge = 0, alice_edge = 0, bob_edge = 0;
        
        for(auto edge : edges) {
            if(edge[0] == 3) {
                if(alice.findUParent(edge[1]) != alice.findUParent(edge[2])) {
                    alice.unionByRank(edge[1], edge[2]);
                    bob.unionByRank(edge[1], edge[2]);
                    alice_edge++;
                    bob_edge++;
                } else {
                    removed_edge++;
                }
            }
        }
            
         for(auto edge : edges) {
            if(edge[0] == 2) {
                if(bob.findUParent(edge[1]) != bob.findUParent(edge[2])) {
                    bob.unionByRank(edge[1], edge[2]);
                    bob_edge++;
                } else {
                    removed_edge++;
                }
            } else if(edge[0] == 1) {
                if(alice.findUParent(edge[1]) != alice.findUParent(edge[2])) {
                    alice.unionByRank(edge[1], edge[2]);
                    alice_edge++;
                } else {
                    removed_edge++;
                }
            }
        }  
        
        return (alice_edge == n-1 && bob_edge == n-1) ? removed_edge : -1;
    }
};