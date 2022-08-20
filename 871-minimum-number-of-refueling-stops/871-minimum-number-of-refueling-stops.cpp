class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size();
        int max_can_reach = startFuel;
        priority_queue<int> pq;
        int i= 0, count = 0;
        while(max_can_reach < target)
        {
            while(i<n && stations[i][0] <= max_can_reach)
            {
                pq.push(stations[i][1]);
                i++;
            }
            
            if(pq.empty())
                return -1;
            
            max_can_reach += pq.top();
            pq.pop();
            count++;
        }
        
        return count;
    }
};