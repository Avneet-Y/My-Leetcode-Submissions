class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int currentgas = 0, start= 0, totalgas = 0;
        
        for (int i=0; i<n; i++) 
        {    
            totalgas += gas[i] - cost[i];
            currentgas += gas[i] - cost[i];
            
            if (currentgas < 0) 
            {
                start = i+1;
                currentgas = 0;
            } 
        }
        if(totalgas < 0)
            return -1;
        return start;
    }
};