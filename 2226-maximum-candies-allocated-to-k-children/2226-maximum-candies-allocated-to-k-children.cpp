class Solution {
public:
     bool isvalid(vector<int>& candies, int n, long long k, int mx)
    {
        long long child = 0;
        for(int i=0; i<n; i++)
        {
            child += (candies[i]/mx);
        }
          if(child >= k)
              return true;
         return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        
        int start = 1;
        // int sum = accumulate(candies.begin(), candies.end(), 0);
        int end = 1e9;
        int ans = 0;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(isvalid(candies, n, k, mid) == true)
            {
                ans = mid;
                start = mid+1;
            }
            else
                end = mid-1;
                
        }
        return ans;
        
    }
};