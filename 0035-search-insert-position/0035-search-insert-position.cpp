//alterntive question to find ceil of an element

class Solution {
public:
    int solve(vector<int>& nums, int start, int end, int target)
    {
        int res = -1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                res = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
            }
        }
        return res;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = solve(nums, 0, n-1, target);
        if(ans == -1)
            return n;
        return ans;
    }
};