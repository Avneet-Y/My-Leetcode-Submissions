class Solution {
public:
     bool is_possible(vector<int>& time, long long mid, int totalTrips)
    {
        int n = time.size();
        long long trips = 0;
        
        for(int i = 0; i < n; i++)
        {
            trips += (mid / time[i]);
        }
        return trips >= totalTrips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long start = 1;
        long long end = 1e14;  //LONG_MAX
        long long ans = 1;
        while(start <= end)
        {
            long long mid = start + (end - start) / 2;
            if(is_possible(time, mid, totalTrips))
            {
                ans = mid; 
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};