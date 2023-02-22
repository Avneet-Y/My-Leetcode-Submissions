class Solution {
public:
    bool isvalid(vector<int>& nums, int k, int maxi, int n)
    {
        int count = 1;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            if(sum > maxi)
            {
                count++;
                sum = nums[i];
            }
            if(count > k)
                return false;
        }
        return true;
    }
    
    int search(vector<int>& nums, int k, int n)
    {
        int sum = 0;
        int maxi = INT_MIN;
        int res = -1;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            maxi = max(nums[i], maxi);
        }
        int start = maxi;
        int end = sum;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(isvalid(nums, k, mid, n) == true)
            {
                res = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return res;
    }
    
    
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        int ans = search(nums, k, n);
        return ans;
        
    }
};