class Solution {
public:
     bool isvalid(vector<int>& nums, int n, int k, int mx)
    {
        int tempsize = 1;
        int tempsum = 0;
        for(int i=0; i<n; i++)
        {
            tempsum += nums[i];
            if(tempsum > mx)
            {
                tempsize++;
                tempsum = nums[i];
            }
            if(tempsize > k)
                return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
         int n = nums.size();
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxi = *max_element(nums.begin(), nums.end());
        
        int start = maxi; 
        int end = sum;
        int ans = -1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(isvalid(nums, n, k, mid) == true)
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