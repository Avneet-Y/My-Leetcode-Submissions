class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> vec;   
    
        int n = plantTime.size(); 
    
        for(int i=0; i<n; i++)
        {
            vec.push_back({growTime[i],plantTime[i]}); 
        }
    
        sort(vec.begin(),vec.end());   
    
        int time = 0;
        int max_days = 0;
    
        for(int i = n-1; i >= 0; i--)
        { 
            time += vec[i].second;    
            max_days = max(max_days, time + vec[i].first);    
        }
        return max_days;
    }
};