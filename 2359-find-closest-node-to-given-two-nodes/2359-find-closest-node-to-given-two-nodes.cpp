class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>dist1(n,-1), dist2(n,-1);
        dist1[node1] = 0;      // Dist of all node from node1
        dist2[node2] = 0;      // Dist of all node from node2
        int dist = 0;
        int i = node1;
        while(1)
        {
            dist1[i] = dist++;
            i = edges[i];
            if(i==-1 or dist1[i]!=-1)
                break;  
        }
        i = node2;
        dist = 0;
        while(1)
        {
            dist2[i] = dist++;
            i = edges[i];
            if(i == -1 or dist2[i] != -1)
                break;
        }
        
        int ans = -1;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(dist1[i] == -1 or dist2[i] == -1)
                continue; 
            if(mini > max(dist1[i], dist2[i]))
            { 
                mini = max(dist1[i], dist2[i]);
                ans = i;
            }
        }
        return ans;
    }
};