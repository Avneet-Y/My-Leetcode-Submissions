class Solution {
public:
    int firstocc(vector<int>& nums, int target, int n)
    {
        int start = 0;
        int end = n-1;
        int res = -1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
            {
                res = mid;
                end = mid-1;
            }
            else if(nums[mid] < target)
            {
                start = mid+1;
            }
            else if(nums[mid] > target)
            {
                end = mid-1;
            }
        }
        return res;
    }
    int lastocc(vector<int>& nums, int target, int n)
    {
        int start = 0;
        int end = n-1;
        int res = -1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
            {
                res = mid;
                start = mid+1;
            }
            else if(nums[mid] < target)
            {
                start = mid+1;
            }
            else if(nums[mid] > target)
            {
                end = mid-1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstocc(nums, target, n);
        int last = lastocc(nums, target, n);
        return {first, last};
        
    }
};