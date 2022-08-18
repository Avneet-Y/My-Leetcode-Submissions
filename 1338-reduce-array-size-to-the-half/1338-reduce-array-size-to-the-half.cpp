class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;    
        priority_queue<int> pq;       //max heap
    
        for(auto it : arr) 
            mp[it]++;    
    
        for(auto it : mp) 
            pq.push(it.second); 

        int ele = 0, Count=0;
        while(!pq.empty())
        {    
            ele+=pq.top();     
            pq.pop();          
            Count++;
        
            if(ele >= n/2) 
                return Count;
        }
    return 0;
    }
};