class Solution {
public:
    int binarylast(vector<int>& nums, int target, int n)
    {
        int start = 0;
        int end = n-1;
        int last = -1;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
            {
                last = mid;
                start = mid+1; 
            }
            else if(nums[mid] > target)
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return last;
    }
    
    int binaryfirst(vector<int>& nums, int target, int n)
    {
        int start = 0;
        int end = n-1;
        int first = -1;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
            {
                first = mid;
                end = mid-1; 
            }
            else if(nums[mid] > target)
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return first;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = binaryfirst(nums, target, n);
        int last = binarylast(nums, target, n);
        return {first, last};
    }
};