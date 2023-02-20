class Solution {
public:
    int search(vector<int>& nums, int start, int end, int target)
    {
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(target == nums[mid])
                return mid;
            else if(target > nums[mid])
            {
                start = mid+1;
            }
            else if(target < nums[mid])
            {
                end = mid-1;
            }
        }
        return start;
        
    }
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = search(nums, 0, n-1, target);
        return ans;
        
    }
};