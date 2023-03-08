class Solution {
public:
    bool isvalid(vector<int>& piles, int h, long long mid)
    {
        int n = piles.size();
        double time = 0;
        for(int i=0; i < n; i++)
        {
            time += ceil(piles[i]*1.0/mid);
            
        }
        if(time <= h)
            return true;
        return false;
    }
    
    int bsearch(vector<int>& piles, int n, int h)
    {
        
        long long maxi = *max_element(piles.begin(), piles.end());
        long long start = 0;
        long long end = maxi;
        if(h == n)
            return maxi;
        
        long long res = -1;
        
        while(start <=  end)
        {
            long long mid = start + (end - start) / 2;
            if(isvalid(piles, h, mid) == true){
                res = mid;
                end = mid - 1;
            }
            else if(isvalid(piles, h, mid) == false){
                start = mid + 1;
            }
        }
        return res;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans = bsearch(piles, n, h);
        return ans;
        
    }
};