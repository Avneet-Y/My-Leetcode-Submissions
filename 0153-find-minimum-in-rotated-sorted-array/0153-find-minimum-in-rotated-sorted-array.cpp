class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int next, prev;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[start] <= nums[end])
                return nums[start];
            next = (mid+1) % n;
            prev = (mid-1+n) % n;
            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next])
            {
                return nums[mid];
            }
            else if(nums[mid] >= nums[start])
            {
                start = mid+1;
            }
            else if(nums[mid] <= nums[end])
            {
                end = mid-1;
            }
        }
        return nums[start];
    }
};