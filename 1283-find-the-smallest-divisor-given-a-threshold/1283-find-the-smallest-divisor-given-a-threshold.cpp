class Solution {
public:
    bool isvalid(vector<int>& nums, int threshold, int n, long long mid)
    {
        double div = 0;
        for(int i=0; i<n; i++)
        {
            div += ceil(nums[i]*1.0/mid);
            if(div > threshold)
            {
                return false;
            }
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
        {
            maxi = max(maxi, nums[i]);
        }
        
        long long start = 0;
        long long end = maxi;
        long long ans = -1;
        while(start <= end)
        {
            long long mid = start + (end-start)/2;
            if(isvalid(nums, threshold, n, mid) == true)
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