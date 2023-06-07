class Solution {
public:
    int binary(vector<int>& nums, int target, int start, int end)
    {
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                end = mid-1;
            else if(nums[mid] < target)
                start = mid+1;
        }
        return -1;
    }
    
    int findmin(vector<int>& nums, int n)
    {
        int start = 0, next, prev;
        int end = n-1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            prev = (mid+n-1)%n;
            next = (mid+1)%n;
            if(nums[next] >= nums[mid] && nums[prev] >= nums[mid])
                return mid;
            
            if(nums[mid] <= nums[end])
                end = mid - 1;
            else if(nums[mid] >= nums[start])
                start = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int index = findmin(nums, n);
        int leftsearch, rightsearch;
        leftsearch = binary(nums, target, 0, index-1);
        rightsearch = binary(nums, target, index, n-1);
        if(leftsearch == -1)
            return rightsearch;
        return leftsearch;    
    }
};