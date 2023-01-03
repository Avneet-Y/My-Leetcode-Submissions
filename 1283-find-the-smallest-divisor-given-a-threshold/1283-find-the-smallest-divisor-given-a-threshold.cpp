//similar to koko eating bananas

class Solution {
public:
    bool isvalid(vector<int>& nums, int threshold, long long mid)
    {
        double div = 0;
        for(int i=0; i<nums.size(); i++)
        {
                div += ceil(nums[i]*1.0/mid);
        }
        if(div <= threshold) 
            return true;
        return false;
    }   
    
    int solve(vector<int>& nums, int n, int threshold)
    {
        long long res = -1;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
        {
            maxi = max(maxi, nums[i]);
        }
        if(threshold == n)
            return maxi;
        long long start = 0;
        long long end = maxi;
        while(start <= end)
        {
            long long mid = start + (end - start)/2;
            if(isvalid(nums, threshold, mid) == true)
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
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        int ans = solve(nums, n, threshold);
        return ans;
    }
};