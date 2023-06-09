class Solution {
public:
    bool isvalid(vector<int>& piles, int h, int n, long long mid)
    {
        double time = 0;
        for(int i=0; i<n; i++)
        {
            time += ceil(piles[i]*1.0/mid);
            if(time > h)
            {
                return false;
            }
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
        {
            maxi = max(maxi, piles[i]);
        }
        
        long long start = 0;
        long long end = maxi;
        long long ans = -1;
        while(start <= end)
        {
            long long mid = start + (end-start)/2;
            if(isvalid(piles, h, n, mid) == true)
            {
                ans = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return ans;
    }
};