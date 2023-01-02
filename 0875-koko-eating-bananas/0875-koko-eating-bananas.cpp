class Solution {
public:
    
    bool isvalid(vector<int>& piles, int h, long long mid)
    {
        int count = 0;
        for(int i=0; i<piles.size(); i++)
        {
                count += piles[i]/mid;
                if(piles[i] % mid != 0)
                    count++;
        }
        if(count <= h) 
            return true;
        return false;
    }   
    
    int solve(vector<int>& piles, int n, int h)
    {
        long long sum = 0, res = -1;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
        {
            sum += piles[i];
            maxi = max(maxi, piles[i]);
        }
        long long start = 1;
        long long end = sum;
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