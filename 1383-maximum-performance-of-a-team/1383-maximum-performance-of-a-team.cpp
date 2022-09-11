class Solution {
public:
       const int mod = (int)1e9 + 7;
     int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k){
      
      priority_queue<int, vector<int>, greater<int>> pq;
      vector<pair<int, int>> vec;
         
      for (int i = 0; i < n; i++)
      {
          vec.push_back({efficiency[i], speed[i]});
      }
      
      sort(vec.rbegin(), vec.rend());   
      long totalspeed = 0, ans = 0;
      for (int i = 0; i < n; i++) 
      {
        int present_eff = vec[i].first;
        int speed = vec[i].second;
        if (pq.size() == k) 
        {	
          totalspeed -= pq.top();
          pq.pop();
        }
          
        pq.push(speed); 		
        totalspeed += speed; 
        ans = max(ans, totalspeed * present_eff); 
      }
      return ans % mod; 
    }
};