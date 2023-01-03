class Solution {
public:
    
    bool isvalid(vector<int>& piles, int h, long long mid)
    {
        double time = 0;
        for(int i=0; i<piles.size(); i++)
        {
                time += ceil(piles[i]*1.0/mid);
        }
        if(time <= h) 
            return true;
        return false;
    }   
    
    int solve(vector<int>& piles, int n, int h)
    {
        long long res = -1;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
        {
            maxi = max(maxi, piles[i]);
        }
        if(h == n)
            return maxi;
        long long start = 0;
        long long end = maxi;
        while(start <= end)
        {
            long long mid = start + (end - start)/2;
            if(isvalid(piles, h, mid) == true)
            {
                res = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return res;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        int ans = solve(piles, n, h);
        return ans;
        
    }
};