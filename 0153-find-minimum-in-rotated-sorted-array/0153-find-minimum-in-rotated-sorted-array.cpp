class Solution {
public:
    int binary(vector<int>& nums, int n)
    {
        int start = 0, next, prev;
        int end = n-1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[start] <= nums[end])
                return nums[start];
            next = (mid+1) % n;
            prev = (mid + n - 1) % n;
            if(nums[prev] >= nums[mid] && nums[next] >= nums[mid])
                return nums[mid];
            else if(nums[start] <= nums[mid])
                start = mid+1;
            else if(nums[mid] <= nums[end])
                end = mid-1;
        }
        return nums[start];
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = binary(nums, n);
        return ans;
        
    }
};